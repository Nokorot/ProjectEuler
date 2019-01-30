import numpy as np

primes_file = "../primes.dat"

def readprimes():
    with open(primes_file, 'rb') as f:
        #f.read(3);
        return np.fromfile(f, dtype='byte');


def primesfrom2to(n):
    """ Input n>=6, Returns a array of primes, 2 <= p < n """
    sieve = np.ones(n/3 + (n%6==2), dtype=np.bool)
    for i in xrange(1,int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[       k*k/3     ::2*k] = False
            sieve[k*(k-2*(i&1)+4)/3::2*k] = False
    return np.r_[2,3,((3*np.nonzero(sieve)[0][1:]+1)|1)]

class primes:
    def __init__(self, n=1000, add=1000):
        self.n = n
        self.add = add

        sieve = np.ones(n/2, dtype=np.bool)
        for i in xrange(3,int(n**0.5)+1,2):
            if sieve[i/2]:
                sieve[i*i/2::i] = False
        self.primes = np.r_[2, (2*np.nonzero(sieve)[0][1::]+1)]

    def genprimes(self, to=None):
        n, m = self.n, self.add
        if to != None:
            m = max(m, to-self.n + 1)
            while to > self.primes[-1]**2-1:
                self.genprimes(self.primes[-1]**2-1)

        sieve = np.ones(m, dtype=np.bool)
        for i in self.primes:
            if i**2 > n+m:
                break
            sieve[(i-(n%i))::i] = False
        self.primes = np.r_[self.primes, np.nonzero(sieve)[0][1::]+n]
        self.n += m

    def isPrime(self, num):
        if num >= self.n:
            self.genprimes(num)
        return self.primes.__contains__(num)

    def __getintem__(self, i):
        while i > len(self.data):
            self.genprimes()
        return self.data[i+1]
