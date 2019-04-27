
S = lambda a,b: sum(map(int,str(a**b)))

M = 0
for b in range(1000):
	for a in range(1000):
		ss = S(a,b)
		if ss > M:
			print("%2d, %2d: %4d" % (a,b,ss))
			M = ss;
