
#include <string>
#include <fstream>
#include <sstream>

//using namespace std;

static std::string PRIMES_FILE = "../primes_1e7.txt";
static int PRIMES_SIZE = 664579;

int fast_atoi( const char* str )
{
    int val = 0;
    while( *str )
        val = val*10 + (*str++ - '0');
    return val;
}

int* read_prime_file(){
	std::string line;
	getline(std::ifstream(PRIMES_FILE), line);

	int* res = new int[PRIMES_SIZE];

	unsigned int p, i;
	std::stringstream ss(line);
	std::string token;

	while (std::getline(ss, token, ',')) {
		res[i++] = fast_atoi(token.c_str());
	}
	return res;
}
