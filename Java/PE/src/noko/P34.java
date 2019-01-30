package noko;
import static noko.Prints.print;

public class P34 {
	
	int[] digets(int n) {
		String s = Integer.toString(n);
		int[] digs = new int[s.length()];
		for(int i=0; i<s.length(); i++)
			digs[i] = Integer.parseInt(s.charAt(i)+"");
		return digs;
	}
	
	int fac(int i) {
		int p = 1;
		for (int j=2;j<=i; j++)
			p *= j;
		return p;
	}
	
	public P34(String[] args) {
		int SUM = 0;
		for(int i = 10; i<1e7; i++) {
			int sum = 0;
			for(int d : digets(i))
				sum += fac(d);
			if (sum == i) {
				SUM += sum;
				print(sum);
			}
			
		}
		print(SUM);
	}
	
}
