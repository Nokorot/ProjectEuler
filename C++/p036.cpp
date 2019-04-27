
#include<bits/stdc++.h>
#include <iostream>

#include <fstream>
#include <string>

#include <sstream>
#include <vector>

using namespace std;

static string PRIMES_FILE = "primes_1e7.txt";
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
	//int* primes = read_prime_file();
	string s;
	bool palid;

	int SUM = 0;

	for (uint i=1; i<1e6; i+=2){
		s = to_string(i);
		int sl = s.length();
		palid = 1;

		int l=0;
		while((i >> l) > 0)
			l++;

		for(int k=0;palid && k<l/2; k++){
			//cout << i << "\t" << k  << "\t" << l << "\t" << ((i >> k) & 1) << "\t" << ((i >> (l-k-1)) & 1) << endl;	
			if (((i >> k) & 1) != ((i >> (l-k-1)) & 1)) 
				palid = 0;
		}

		for(int k=0;palid && k<sl/2; k++){
			if (s[k] != s[sl-k-1]) 
				palid = 0;	
		}

		if (palid){
			SUM += i;
			cout << i << endl;
		}

	}
	cout << "\n" << SUM << endl;
	
	return 0;
}
