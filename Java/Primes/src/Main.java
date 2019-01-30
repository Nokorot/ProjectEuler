import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class Main {

	
	public static void main(String[] args) throws IOException {

//		int[] primes = sive(new byte[(int) 1e8 - 2], 2);
		
		int[] primes = readPrimes();
		System.out.println(primes[primes.length-1]);
		
//		writePrimes(primes);
		
//		for(int p : primes)
//			System.out.println(p);
		/*
		for(int i=0; i<10;i++)
		
		int[] primes = sive(new byte[10], 2);
		System.out.println(Arrays.toString(primes));

		byte[] data = new byte[10];
		sive(primes, data, 12);
		
		System.out.println(Arrays.toString(sive(data, 12)));
		*/
	}
	
}
