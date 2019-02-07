
#include <iostream>

#include <string>
#include <vector>

#include "primes.cpp"

using namespace std;

int main()
{
  int size;
  int* primes;
  readPrimes(primes, size);

  int some[20];

  std::copy(primes, primes+10, some+5);

  for(int i=0; i<20; i++)
    std::cout << some[i] << '\n';

  return 0;
}
