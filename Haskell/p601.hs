
streak n = funk 1
    where funk k
            | (mod (n+k) (k+1)) /= 0 = k
            | otherwise = funk (k+1)

isStreak n s = func 1
    where func k
            | k == s = mod (n+k) (k+1) /= 0
            | (mod (n+k) (k+1)) /= 0 = False
            | otherwise = func (k+1)

aP s n = func 1 []
    where func i c
            | i == n = c
            | isStreak i s = func (i+1) (i:c)
            | otherwise = func (i+1) c

aA p = func (map streak (tail [1,p+1..])) 2
    where func (x:xs) c
            | x /= (head xs) = ((c, x), p*c)
            | otherwise = func xs (c+1)

aB = func [] 1
    where func m p  = let (nm, np) = (aA p) in nm : (func (nm:m) np)

bP s n = func (n-2) aB
    where func p ((c,ss):xs)
            | ss == s = (c-1) * (div p c) + (mod p c)
            | ss > s = 0
            | otherwise = func (div p c) xs
