
import numpy as np
from lib import primes

def factors(n):
	fs = {}
	divC = 1;
	for p in primes()[1:]:
		if (p > n):
			break;
		if (n % p == 0):
			fs[p] = 1;
			n /= p;
		while (n % p == 0):
			fs[p] += 1
			n /= p;
		divC *= fs.get(p, 0)+1;
	return fs, divC;

def divisors(n):
	facs, dc = factors(n);
	fs = np.array(facs.keys(), np.uint32)
	ms = np.array(facs.values(), np.uint32)
	pows = np.zeros(len(fs), np.uint32);

	res = np.zeros(dc-1, np.uint32);
	for i in range(dc-1):
		res[i] = np.prod(fs**pows)
		for j in range(len(fs)):
			if (ms[j] > pows[j]):
				pows[j] += 1;
				break;
			else:
				pows[j] = 0

	return res;

with open('out.txt', 'r') as f:
	tmp = f.read().split(',')[:-1]
	k = len(tmp)
	l = int(tmp[-1]);

outf = open('out.txt', 'a');

for n in range(l+1,20000):
	divs = divisors(n)
	if (np.sum(divs) > n):
		outf.write("%d," % n)
		if (n % 2 != 0):
			print(n)

outf.close()
print(k)
