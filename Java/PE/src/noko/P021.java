package noko;
import static noko.Primes.primes;
import static noko.Prints.*;
import static noko.Utils.*;

import java.io.IOException;

public class P21 {

	int[] primes = primes();

	int divisorSum(int[] divs) {
		int s=0;
		for(int i=0;i<divs.length-1;i++)
			s += divs[i];
		return s;
	}

	int divisorSum(int n) {
		return divisorSum(divisors(n));
	}

	public P21(String[] args) throws IOException {
		int SS = 0;
		int N = 100000;

		int[] divSums = new int[N];

		for(int n=1; n<N; n++) {
			if(isPrime(n))
				divSums[n] = 1;
			divSums[n] = divisorSum(n);
		}

		for(int i=0; i<divSums.length; i++)
			for(int j=i+1; j<divSums.length; j++)
				if (divSums[i] == j && divSums[j] == i)  {
					SS += i + j;
					printJ(", ", i, j);
				}

		print(SS);
	}

}
