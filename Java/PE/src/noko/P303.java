package noko;

import static noko.Prints.*;
import static noko.Utils.*;

import java.math.BigInteger;

// Not Solved !!
public class P303 {

	long fast_atoi(char[] str, int a, int b) {
		long val = 0;
		for (int i = a; i < b; i++)
			val = val * 10 + (str[i] - '0');
		return val;
	}

	long fast_atoi(char[] str) {
		return fast_atoi(str, 0, str.length);
	}

	BigInteger atoi(char[] str) {
		return new BigInteger(new String(str));
	}

	boolean divides(char[] str, int n) {
		final int k = 18;

		for (int i = 0; i < str.length - 19; i++)
			if (str[i] != '0') {
				long rem = 0;
				for (int j = 0; j * k < str.length; j++) {
					long ll = fast_atoi(str, max(0, str.length - (j + 1) * k), str.length - j * k);
					rem = (rem + (ll % n) * modpow(modpow(10, k, n), j, n)) % n;
				}
				return rem == 0;
			}

		return fast_atoi(str) % n == 0;
	}

	long f0(int n, char[] cc) {
		for (int i = 0; i < cc.length; i++)
			cc[i] = '0';
		do {
			boolean kk = false, tt = false;
			for (int i = cc.length - 1; i >= 0; i--) {
				if (cc[i] == '2')
					cc[i] = '0';
				else {
					cc[i] = (cc[i] == '1') ? '2' : '1';
					kk = true;
					break;
				}
				if (i < cc.length - 14)
					tt = true;
			}
			if (tt)
				printf("%d: %d\n", n, atoi(cc));
			if (!kk)
				return -1;
		} while (!divides(cc, n));// fast_atoi(cc) % n != 0);
		return fast_atoi(cc);
	}
	
	public P303(String[] args) {
		char[] cc = new char[20];
		long ss = 0;

		for (int n = 1; n <= 1000; n++) {
			if (f0(n, cc) < 0)
				;
			print(n, fast_atoi(cc));
			ss += fast_atoi(cc) / n;
		}

		print(f0(9, cc));
		print(f0(99, cc));
		print(f0(999, cc));

	}

}
