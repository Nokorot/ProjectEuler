
#include<bits/stdc++.h>
#include <iostream>

#include <fstream>
#include <string>

#include <sstream>
#include <vector>

#include "primes.cpp"
#include "utils.cpp"

using namespace std;

bool contains(int n, int* x, int max){
	int a=0, b=max;
	while (a < b) {
		int k = a+(b-a)/2;
		if (x[k] == n)
			return true;
		if (x[k] < n)
			a = k+1;
		else
			b = k-1;
	}
	return x[a] == n || x[b] == n;
}

int main()
{
	int* primes; int size;
	readPrimes(primes, size);

	int p, i = 0;

	string s;
	bool cprime;
	char* ss = new char[10];

	while ((p = primes[i++]) < 1e6){
		cprime = 1;
		s = to_string(p);
		strcpy(ss, s.c_str());
		for(int j=0;j<s.length()-1; j++){
			char c = ss[0];
			for(int k=0;k<s.length()-1; k++) {
				ss[k] = ss[k+1];
			}
			ss[s.length()-1] = c;
			if (!contains(fast_atoi(ss), primes, 1e6)){
				cprime = 0;
			}
		}
		if (cprime)
			cout << p << endl;

	}


	return 0;
}
