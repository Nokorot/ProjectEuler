package noko;

import static noko.Prints.print;

public class P1 {

	public P1(String[] args){
		int sum = 0;
		int[] ll = new int[]{0, 3, 5, 6, 9, 10, 12};
		for (int i=0; i*15<1000;i++) {
			for (int l : ll) {
				if (i*15 + l < 1000)
					sum += i*15 + l;

			}
		}
		print(sum);
	}

}
