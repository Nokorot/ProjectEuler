
from primes import readprimes

__primes_data = None;
def primes():
    global __primes_data;
    if (__primes_data == None):
        __primes_data = readprimes()
    return __primes_data;
