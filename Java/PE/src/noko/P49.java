package noko;
import static noko.Primes.primes;
import static noko.Prints.printJ;

public class P49 {

	boolean sameDigts(int a, int b) {
		char[] as = Integer.toString(a).toCharArray(); 
		char[] bs = Integer.toString(b).toCharArray();
		
		if (as.length != bs.length)
			return false;
		loopA:
		for(char aa : as){
			for(char bb : bs) 
				if(bb == aa)
					continue loopA;
			return false;
		}
		loopB:
		for(char bb : bs){
			for(char aa : as) 
				if(bb == aa)
					continue loopB;
			return false;
		}
		return true;
	}
	
	public P49(String[] args) {
		int[] primes = primes();

		int a=0, b=0;
		for (int i = 0; i < primes.length; i++) {
			if (primes[i] < 1e3)
				a = i + 1;
			else if (primes[i] >= 1e4) {
				b = i;
				break;
			}
		}
		
		for(int i=a; i<b;i++) {
			for(int j=i+1; j<b; j++){
				int next = (2*primes[j] - primes[i]);
				if (next > primes[b])
					break;
				if (!sameDigts(primes[i],primes[j]) || !sameDigts(primes[i], next) )
					continue;
				for(int k=j; k<b; k++) {
					if(primes[k] == next) {
						printJ(", ", primes[i], primes[j], primes[k]);
					}else if (primes[k] > next){
						break;
					}
				}
			}
		}

	}

}
