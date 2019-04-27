

long long fast_atoi( const char* str )
{
    long val = 0;
    while( *str )
        val = val*10 + (*str++ - '0');
    return val;
}

int prod(int* x, int xs) {
	int p = 1;
	for(int i=0;i<xs;i++)
		p *= x[i];
	return p;
}

int pow(int n, int k) {
    int p(1);
    for(int i=0;i<k;i++)
        p*=n;
    return p;
}


/*std::vector< std::pair<int,int> > factros( int* primes, int n )
{
    std::vector< std::pair<int,int> > fs;

    int p, i = 0;
    while ((p = primes[i++]) < n){
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


std::vector<int> divisors( int* primes, int n )
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

  std::vector<int> res;
  for (i=0; i<facs.size();)
  {
    for (p=1, i=0; i<facs.size(); ++i)
      p *= pow(fs[i], pws[i]);
    res.push_back(p);
    for (i=0; i<facs.size(); ++i)
    {
        if ( ms[i] > pws[i])
          { pws[i]++; break; }
        else
          { pws[i] = 0; }
    }
  }
  return res;
}
*/
