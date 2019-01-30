
#include<bits/stdc++.h>
#include <iostream>

#include <fstream>
#include <string>

#include <sstream>
#include <vector>


long fast_atoi( const char * str )
{
    long val = 0;
    while( *str ) {
        val = val*10 + (*str++ - '0');
    }
    return val;
}

using namespace std;

int main()
{
	string line;
	ifstream myfile("primes_1e7.txt");
	getline(myfile, line);

	long N(1e5);
	int X[N];
	unsigned long p, C(10);
	bool Done(false);

	stringstream ss(line);
	string token;

	for (long i = 0; i < N; i++)
		X[i] = 0;


	while (std::getline(ss, token, ',')) {
		
		char * tab2 = new char [token.length()+1];
		strcpy (tab2, token.c_str());
		p = fast_atoi(tab2);

		while (C < p) {
			if (X[C] == 4 && X[C + 1] == 4 && X[C + 2] == 4 && X[C + 3] == 4) {
				Done = true;
				cout << C << endl;
				break;
			}
			C++;
		}
		if (p > N ||  Done)
			break;

		for (long i = p; i < N; i += p) {
			X[i] += 1;
		}
	}
	
	//for (int i = 0; i < N; i++)
	//	cout << i << "\t" << X[i] << endl;
	
	return 0;
}
