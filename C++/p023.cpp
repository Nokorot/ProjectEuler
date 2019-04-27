
#include <iostream>

#include <vector>
#include <utility>

#include "primes.cpp"
#include "utils.cpp"

std::vector< std::pair<int,int> > factros( int* primes, int n )
{
    std::vector< std::pair<int,int> > fs;

    int p, i = 0;
    while ((p = primes[i++]) <= n){
      if (p > n) break;
      if (n % p == 0) {
        fs.push_back(std::pair<int,int>(p, 1));
        n /= p;
      } while ( n % p == 0) {
        fs.back().second++;
        n /= p;
      }
    }
    return fs;
}

int divisorsum( int* primes, int n )
{
  int p, i = 0;

  auto facs = factros(primes, n);
  int fs[facs.size()], ms[facs.size()], pws[facs.size()];
  for (auto pr : facs)
  {
      fs[i] = pr.first;
      ms[i] = pr.second;
      pws[i++] = 0;
  }

  int res=0;
  for (i=0; i<facs.size();)
  {
    for (p=1, i=0; i<facs.size(); ++i) {
      //printf("%d %d, %d\n", n,  fs[i], pws[i]);
      p *= pow(fs[i], pws[i]);
    }
    res += p;
    for (i=0; i<facs.size(); ++i)
    {
        if ( ms[i] > pws[i])
          { pws[i]++; break; }
        else
          { pws[i] = 0; }
    }
  }
  return res-n;
}

void fillMask(bool*& mask, const int& nn, const int& d)
{
  int i, k;
  for (int i=nn-1; i>=0; --i)
    if (mask[i] || i == 0) {
      for (k=i+d; k<nn; k+=d){
        if (mask[k]) break;
        mask[k] = 1;
      }
    }
}

int main()
{
  int* primes; int size;
	readPrimes(primes, size);

  /*for (auto pr : factros(primes, 51))
    std::cout << pr.first << ", " << pr.second << std::endl;*/

  std::vector<int> v;

  int n, nn = 21123;
  bool* mask = new bool[nn];
  for (n=0; n<nn; n++)
    mask[n] = 0;

  for (n=2; n<nn; ++n)
    if (divisorsum(primes, n) > n){
      //printf("-%d\n", n);
      v.push_back(n);
      for (int d : v)
        if (d+n < nn)
          mask[d+n] = 1;
    }

  int k = 0;
  for (n=0; n<nn; n++)
    if(!mask[n]) k+=n;// printf("%d\n", n);

    printf("%d\n", k);

}
