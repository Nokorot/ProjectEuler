#include <iostream>
#include <string>

#include "utils.cpp"

int conprod(int k, int n, char* res)
{
  int off(0);
  for(int i=1;i<=n;i++)
  {
      std::string s = std::to_string(k*i);
      std::copy(s.c_str(), s.c_str()+ s.length(), res+off);
      off += s.length();
  }
  res[off]=0;
  return off;
}

bool pandigital(const char* pchar)
{

  for (int i=0; pchar[i]!=0; i++)
    for (int j=0; j<i; j++)
      if (pchar[i] == pchar[j])
        return false;
  return true;
}

bool pandigital(int k)
{ return pandigital(std::to_string(k).c_str()); }

int main() {
  char* cp = new char[20];
  for (int n = 2; n<10;n++){
    int k=pow(10, 10/n);

    printf("%d\n", k);

    conprod(k , n, cp);
    long kk = fast_atoi(cp);
    while (conprod(k , n, cp) > 9 || !pandigital(cp)){
      if (kk < fast_atoi(cp))
        printf("%s\n", "Something is off");
      kk = fast_atoi(cp) ;
      k--;
    }

    printf("%s, k: %d, n: %d\n", cp, k, n);
  }
}
