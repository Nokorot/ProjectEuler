package noko;
import java.math.BigInteger;

import static noko.Prints.printf;

// Solved
public class P56 {
	
	int S(int a, int b) {
		BigInteger bigA = BigInteger.valueOf(a);
		BigInteger pow = BigInteger.valueOf(1); 
		for(int i=0;i<b;i++)
			pow = pow.multiply(bigA);
		int sum=0;
		for(char c : pow.toString().toCharArray())
			sum += Integer.parseInt(c+"");
		return sum;
	}
	
	public P56(String[] args) {
		int m=0;
		for(int a=1; a<100; a++)
			for(int b=90; b<100; b++) {
				int ss = S(a, b);
				if (ss > m) {
					printf("%3d, %3d: %4d\n", a,b, ss);
					m = ss;
				}
			}	
	}
	
}

/*
 * 
161, 998: 10288
173, 991: 10289
173, 996: 10432
188, 989: 10502
 * 
 */

