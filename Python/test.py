
import numpy as np
from lib import primes

np.array([0xff+1,2], 'int32').tofile('file.bin')

print(np.fromfile('file.bin', 'int32'))
#primes = primes();
print (primes()[0:10])
