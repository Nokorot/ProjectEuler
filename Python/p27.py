
# result: -59231
# Correct !

from itertools import product
from primes import primes

prms = primes()

def primeCount(a, b):
    n = 0
    while prms.isPrime(n**2 + a*n + b):
        n +=1;
    return n

counts = map(lambda x: [primeCount(*x), x[0], x[1]], \
        product(range(-1000, 1000+1), repeat=2))


solution = max(counts, key=lambda x: x[0])

print solution
print solution(1) * solution(2)
