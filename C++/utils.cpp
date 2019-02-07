
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
