
import numpy as np
import time

with open("../C++/primes_1e7.txt", "r") as f:
	X = f.read().split(',')
	tprimes = np.array( [int(i) for i in X[:-1] ] )

N = int(1e6)
Done = False
C = 10

k = 4
g = np.array([k]*k)

t0 = time.time()
X = np.zeros(N,int)
for p in tprimes:
    
	while (C < p):
		if all(X[C:C+k] == g):
			Done = True
			print(C)
			break
		C+=1

	if (p > N or  Done):
		break

	for i in range(p,N,p):
		X[i] += 1;

for (i, v) in enumerate(X):
	pass#print(i,"\t", v)

print(time.time()- t0)
