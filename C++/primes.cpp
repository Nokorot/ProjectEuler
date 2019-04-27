
#include <string>
#include <fstream>


/* TODO
typedef struct {
  int* primes;
  int size;
} Primes;*/

static const std::string primesFile = "../primes.dat";

static int bytes2int(char* data, int i) {
  return ((data[i+0] <<  0) & 0x000000ff) | ((data[i+1] <<  8) & 0x0000ff00)
       | ((data[i+2] << 16) & 0x00ff0000) | ((data[i+3] << 24) & 0xff000000);
}

static bool readPrimes(int*& primes, int& size)
{
  std::ifstream is (primesFile, std::ifstream::binary);
  if (!is) {
    return false;
  }
  is.seekg (0, is.end);
  int length = is.tellg();

  is.seekg (0, is.beg);
  char* buffer = new char[length];

  is.read (buffer,length);
  is.close();

  size = length / sizeof(int)-1; // 5761455 /// bytes2int(buffer, 0);
  primes = new int[size];
  for(int i=0;i<size;i++){
    primes[i] = bytes2int(buffer, (i+1)*sizeof(int));
  }
  delete[] buffer;
  return true;
}
