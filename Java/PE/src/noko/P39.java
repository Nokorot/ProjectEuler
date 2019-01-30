package noko;

import static noko.Prints.print;
import static noko.Utils.*;

import java.util.Arrays;

import static noko.Sorting.*;

public class P39 {
	
	public P39(String[] args) {
		int M = 1000;
		int[] tt = new int[3];
		
		int x;
		int[] res = new int[M];
		
		for (Triple t : Triple.pythogTriples(100, false)) {
			int a = 1;
			t.times(tt, a++);
			while ((x=sum(tt)) < M) {
				if(x == 840)
					print(tt, t);
				res[x]++;
				t.times(tt, a++);
			}
		}
		
		int m = 0;
		for(int i=0;i<res.length;i++)
			if (res[i] > res[m])
				m = i;
		print(m, res[m]);
	}
}

class Triple {
	int[] tt;
	public Triple(int[] tt) {
		if (tt[0]%2 == 0 && tt[1]%2 == 0 && tt[2]%2 == 0)
			for (int i=0;i<3;i++)
				tt[i] = tt[i]/2;
		this.tt = tt;
	}
	public Triple(int a, int b, int c) {
		this(new int[] {a,b,c});
	}
	public void times(int[] res, int a) {
		for (int i=0;i<3;i++)
			res[i] = tt[i]*a;
	}
	public String toString() {
		return Arrays.toString(tt);
	}

	public static Triple[] pythogTriples(int N, boolean ordered) {
		Triple[] triples = new Triple[N*(N-1)/2];

		int c = 0;
		for(int u=1;u<=N; u++) 
			for (int v=1; v<u; v++)
				if (gcd(u,v) == 1 && (ordered || u*u-v*v < 2*u*v))
					triples[c++] = new Triple(u*u-v*v, 2*u*v, u*u+v*v);

		Triple[] res = new Triple[c];
		for(int i=0;i<c;i++)
			res[i] = triples[i];
		
		radixsort((Object t) -> sum(((Triple) t).tt), res);
		return res;
	}
}