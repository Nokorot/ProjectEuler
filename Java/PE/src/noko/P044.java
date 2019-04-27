package noko;
import static noko.Prints.print;

import java.util.Arrays;

public class P44 {

	int pantaNum(int n) {
		return n * (3 * n - 1) / 2;
	}

	int[] A() {
		int aa = 0;
		for (int k = 1; true; k++) {
			loopA: for (int j = 0; j < k; j++) {
				int S = pantaNum(j) + pantaNum(k);
				int D = pantaNum(j) - pantaNum(k);
				boolean cd = false;
				for (int i = 0; (aa = pantaNum(i)) <= S; i++) {
					if (aa == D)
						cd = true;
					else if (!cd && aa > D)
						continue loopA;
					else if (cd && aa == S)
						return new int[] { pantaNum(j), pantaNum(k), D, S };
				}
			}
		}
	}

	public P44(String[] args) {
		print(Arrays.toString(A()));
	}

}