
def take(n, X):
	for (c,x) in zip(range(n), X):
		yield x

def N():
	n = 1
	while True:
		yield n
		n+=1

def S():
	x = 290797
	while True:
		yield x
		x = (x**2) % 50515093

def T(p):
	for x in S(): yield x%p

'''
def N(p,q):
	s = 0
	for (n,x) in zip(range(q), T(p)):
		x*p**n
'''

def ff(p):
	s,f,n = 0,0,1
	while True:
		yield f
		f = n + (p-1)*s
		s += f
		n += 1


def nf(p, q):
	s = 0
	for (x,y) in zip(take(q,T(p)), take(q,ff(p)) ):
		s += x*y
	return s


def ffm(p, m):
	s,f = 0,0
	for n in range(1,m+1):
		yield f
		f = n + (p-1)*s
		s += f
	while True:
		yield f

#sdef gzip(x, y):


def nfm(p, q, m):
	s = 0
	pm = p**m
	for (n,x,y) in zip( range(q), T(p), ffm(p, m) ):
		print( n )
		s += x*y
		s %= pm
	return s

#print( nfm(3,10**4, 20) )

print( nfm(61,10**7, 10) ) #:= 368076460709687735
