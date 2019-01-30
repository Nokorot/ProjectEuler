
def printf(str, *args):
    print(str.format(*args) % args)

def prod(xs):
    p = 1
    for x in xs:
        p *= x
    return p;

with open("../primes_1e7.txt", "r") as f:
    primes = [int(x) for x in f.read().split(',')[:int(1e6)]];

def factors(n):
    res = {};
    for p in primes:
        if (p>n):
            break;
        if (n % p == 0):
            res[p] = 1;
            n /= p;
        while (n % p == 0):
            res[p]+=1;
            n /= p;
    return res

def numOfDivisors(n):
    res = 1;
    for p, m in factors(n).items():
        res *= (m+1);
    return res;

def divisors_gen(factors):
    val = list(factors.values());
    facts = list(factors.keys());
    x = [0]*len(val)
    done = False
    while not done:
        yield prod(map(lambda t: pow(t[0], t[1]), zip(facts, x)))

        for i in range(len(val)):
            if (x[i] == val[i]*2):
                x[i] = 0;
                if(i==len(val)-1):
                    done = True;
            else:
                x[i] += 1
                break;

def divisors(n):
    return list(filter(lambda x: x<=n, divisors_gen(factors(n))));

import sys

def solutions(n, tol=1e-5):
    res = []
    divs = divisors(n)
    for x in range(n+1, n*2+1):
        y = 1/(1./n - 1./x)
        ry = round(y)
        if (abs(y-ry) < tol):
            res.append((x,ry))
            print(f"{x}, {ry}, {x-n}, {divs.__contains__(x-n)}")
    return res



i = 2;
m = 0;
step = 2
while True:
    sols = len(divisors(i))
    if sols > m:
        facs = list(factors(i).keys())
        step = max(prod(facs[:-1]), step)
        print(f"{i:6d} {sols:4d}, {step}, {factors(i)}")
        m = sols;
    i += step;


## Final solution output:
"""
     2    2, 2, {2: 1}
     4    3, 2, {2: 2}
     6    5, 2, {2: 1, 3: 1}
    12    8, 2, {2: 2, 3: 1}
    24   11, 2, {2: 3, 3: 1}
    30   14, 2, {2: 1, 3: 1, 5: 1}
    60   23, 2, {2: 2, 3: 1, 5: 1}
   120   32, 2, {2: 3, 3: 1, 5: 1}
   180   38, 2, {2: 2, 3: 2, 5: 1}
   210   41, 6, {2: 1, 3: 1, 5: 1, 7: 1}
   360   53, 6, {2: 3, 3: 2, 5: 1}
   420   68, 6, {2: 2, 3: 1, 5: 1, 7: 1}
   840   95, 6, {2: 3, 3: 1, 5: 1, 7: 1}
  1260  113, 6, {2: 2, 3: 2, 5: 1, 7: 1}
  1680  122, 6, {2: 4, 3: 1, 5: 1, 7: 1}
  2520  158, 6, {2: 3, 3: 2, 5: 1, 7: 1}
  4620  203, 30, {2: 2, 3: 1, 5: 1, 7: 1, 11: 1}
  7560  221, 30, {2: 3, 3: 3, 5: 1, 7: 1}
  9240  284, 30, {2: 3, 3: 1, 5: 1, 7: 1, 11: 1}
 13860  338, 30, {2: 2, 3: 2, 5: 1, 7: 1, 11: 1}
 18480  365, 30, {2: 4, 3: 1, 5: 1, 7: 1, 11: 1}
 27720  473, 30, {2: 3, 3: 2, 5: 1, 7: 1, 11: 1}
 55440  608, 30, {2: 4, 3: 2, 5: 1, 7: 1, 11: 1}
 83160  662, 30, {2: 3, 3: 3, 5: 1, 7: 1, 11: 1}
110880  743, 30, {2: 5, 3: 2, 5: 1, 7: 1, 11: 1}
120120  851, 210, {2: 3, 3: 1, 5: 1, 7: 1, 11: 1, 13: 1}
180180 1013, 210, {2: 2, 3: 2, 5: 1, 7: 1, 11: 1, 13: 1}
240240 1094, 210, {2: 4, 3: 1, 5: 1, 7: 1, 11: 1, 13: 1}
360360 1418, 210, {2: 3, 3: 2, 5: 1, 7: 1, 11: 1, 13: 1}
720720 1823, 210, {2: 4, 3: 2, 5: 1, 7: 1, 11: 1, 13: 1}
"""


# For testing
k = eval(sys.argv[1])

print(factors(k))
print(sorted(divisors(k)))
print(len(divisors(k)))
print(len(solutions(k)))


## Brot force mathod
'''
    2   2
    4   3
    6   5
   12   8
   24  11
   30  14
   60  23
  120  32
  180  38
  210  41
  360  53
  420  68
  840  95
 1260 113
 1680 120
 2310 121
 2520 158
 4620 198
 7560 206
 9240 274
13860 338
18480 365
27720 473
55440 608
'''


# Manual calculations:
'''
1, 2, 3, 5, 7, 11, 13

1, 2, 3, 4,   5,  6, 7, 8, 9, 10
1, 2, 4, 6, 2^4, 12
'''
