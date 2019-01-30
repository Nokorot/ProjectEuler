import java.io.*;
import java.util.Scanner;

public class Primes {

	public static final String primesTextFile = "../../primes_1e7.txt";
	public static final String primesFile = "../../primes.dat";
	
	private static void int2bytes(byte[] data, int value, int i) {
		data[i+0] = (byte) ((value >> 24) & 255);
		data[i+1] = (byte) ((value >> 16) & 255);
		data[i+2] = (byte) ((value >>  8) & 255);
		data[i+3] = (byte) ((value >>  0) & 255);
	}
	
	private static int bytes2int(byte[] data, int i) {
		return ((data[i+0] << 24) & 0xff000000) | ((data[i+1] << 16) & 0x00ff0000) 
		     | ((data[i+2] <<  8) & 0x0000ff00) | ((data[i+3] <<  0) & 0x000000ff);
	}
	
	private static int[] primes() throws FileNotFoundException {
		Scanner scan = new Scanner(new File("../../primes_1e7.txt"));
		String[] ss = scan.nextLine().split(",");
		int[] ps = new int[ss.length];
		for (int i = 0; i < ss.length; i++)
			ps[i] = Integer.parseInt(ss[i]);
		return ps;
	}
	
	private static void writePrimes(int[] primes) throws IOException {
		byte[] data = new byte[primes.length*4];
		System.out.println("Write");
		for (int i=0; i<primes.length; i++) 
			int2bytes(data, primes[i], i*4);
		
		DataOutputStream os = new DataOutputStream(new FileOutputStream(primesFile));
		os.writeInt(primes.length);
		
		try     { os.write(data); } 
		finally { os.close();     }
	}
	
	private static void appendPrimes(int[] primes) throws IOException {
		FileOutputStream os = new FileOutputStream("data.bin", true);
		
		byte[] data = new byte[primes.length*4];
		for (int i=0; i<primes.length; i++) 
			int2bytes(data, primes[i], i*4);
		
		try     { os.write(data); } 
		finally { os.close();     }
	}
	
	private static void appendPrimes2(int[] primes) throws IOException {
		RandomAccessFile raf = new RandomAccessFile(primesFile, "rw");
		
		int l = raf.readInt() + primes.length;
		raf.seek(0);
		raf.writeInt(l);
		
		raf.seek(raf.length());
		
		byte[] data = new byte[primes.length*4];
		for (int i=0; i<primes.length; i++) 
			int2bytes(data, primes[i], i*4);
		
		try     { raf.write(data); } 
		finally { raf.close();     }
	}
	
	@SuppressWarnings("resource")
	public static int[] readPrimes(String file) throws IOException {
		DataInputStream is = new DataInputStream(new FileInputStream(file));
		int l = is.readInt();
		
		int[] primes = new int[l];
		byte[] data = is.readAllBytes();
		
		for (int i=0; i<l; i++) 
			primes[i] = bytes2int(data, i*4);
		return primes;
	}
	
	public static int[] readPrimes() throws IOException {
		return readPrimes(primesFile);
	}
	
	@SuppressWarnings("resource")
	public static int[] readPrimes(long off, int len) throws IOException {
		RandomAccessFile raf = new RandomAccessFile(primesFile, "r");
		
		int[] primes = new int[len];
		byte[] data = new byte[len*4];
		raf.seek(off);
		raf.read(data);
		
		for(int i=0;i<len;i++)
			primes[i] = bytes2int(data, i*4);
		return primes;
	}
	
	private static int[] sive(byte[] data, int off) {
		int count = 0;
		for(int i=0; i<data.length; i++) {
			if (data[i] != 1) {
				count += 1;
				for(int j=2*i+off;j<data.length; j+=i+off) 
					data[j] = 1;
			}
		}
		int[] res = new int[count];
		int c=0;
		for(int i=0;i<data.length; i++) 
			if(data[i] != 1) 
				res[c++] = i+off;
		return res;
	}
	
	private static void sive(int[] primes, byte[] data, int off) {
		for (int p : primes) {
			int poff = off % p == 0 ? 0 : p-(off % p);
			
			System.out.printf("%d, %d\n", p, poff);
			for(int j=poff; j < data.length; j+=p) 
				data[j] = 1;
		}
	}
	
}
