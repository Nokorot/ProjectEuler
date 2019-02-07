
#include<bits/stdc++.h>
#include <iostream>

#include <fstream>
#include <string>

#include <sstream>
#include <vector>

#include <utility>

using namespace std;

static string PRIMES_FILE = "../primes_1e7.txt";
static int* primes;
static int PRIMES_SIZE = 664579;

int fast_atoi( const char* str ){
    int val = 0;
    while( *str )
        val = val*10 + (*str++ - '0');
    return val;
}

int* read_prime_file(){
	string line;
	getline(ifstream(PRIMES_FILE), line);

	int* res = new int[PRIMES_SIZE];

	unsigned int p, i;
	stringstream ss(line);
	string token;

	while (std::getline(ss, token, ',')) {
		res[i++] = fast_atoi(token.c_str());
	}
	return res;
}

bool contains_ordered(int n, int* x, int max){
	int a=0, b=max;
	while (a < b) {
		int k = a+(b-a)/2;
		cout << k << "\t" << x[k] << endl;
		if (x[k] == n)
			return true;
		if (x[k] < n)
			a = k+1;
		else
			b = k-1;
	}
	return x[a] == n || x[b] == n;
}

int prod(int* x, int xs) {
	int p = 1;
	for(int i=0;i<xs;i++)
		p *= x[i];
	return p;
}

list<pair<int, int>> factors(int* primes, int n) {
	list<pair<int,int>> facs;
	for(int i=0; i<PRIMES_SIZE; i++){
		int p = primes[i];
		if (p>n)
			return facs;
		if (n % p == 0){
			facs.push_back(pair<int, int>(p, 0));
			n = n/p;
		}
		while (n % p == 0) {
			facs.back().second += 1;
			n = n/p;
		}
	}
	return facs;
}

int solutions(int* primes, int n){
	return 0;
}

int main()
{
	primes = read_prime_file();
	string s;

	list<pair<int,int>> facs = factors(primes, 10);
	list<pair<int,int>>::iterator it;
	for (it = facs.begin(); it != facs.end(); ++it){
			cout << "Hey";
	    printf("%d , %d\n", it->first, it->second);
	}

	return 0;
}
