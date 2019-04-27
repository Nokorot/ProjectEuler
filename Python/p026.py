
import numpy as np

def Problem26():

    def decCycle(denom):
        num = 1; count = 0;
        rep = []
        while num != 0:
            if rep.__contains__(num):
                return count - rep.index(num);
            rep.append(num)
            num = num * 10 % denom;
            count += 1;
        return 0

    j,m = 2,0
    for i in range(2, 1000):
        if decCycle(i) > m:
            m = decCycle(i)
            j = i
    print j

Problem26()
