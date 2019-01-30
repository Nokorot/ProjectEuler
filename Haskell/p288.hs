
fac x
  | x <= 0 = 1
  | otherwise = x * (fac (x-1))

factors p x
  | mod x p == 0 = 1 + factors p (div x p)
  | otherwise = 0

_N = 1 : map (+1) _N

s = 290797 : [mod (x^2) 50515093 | x <- s ]

t p = map (\x -> mod x p) s

tN p q = take q (t p)
n p q = sum (take q (map (\(a,n) -> a*p^n) (zip (t p) (0 : _N))))

sff p = 0 : [a+b | (a,b)<- zip (sff p) (ff p)]
ff p = 0 : [n + (p-1)*s | (n,s) <- zip _N (tail (sff p))]

nf p q = sum (take q (map (\(x,y)-> x*y) (zip (t p) (ff p))))

-- values mod (p^m)
ffm p m = (take m (ff p)) ++ (repeat ((ff p) !! m))

tfm p m = (map (\(x,y)-> x*y) (zip (t p) (ffm p m)))
tfms p m = [(a+b) | (a,b)<- zip (sff p) (ff p)]

msum xs m = f 0 xs
  where
    f s [] = s
    f s (x:xs) = f (mod (s+x) m) xs

nfm p q m = msum (take q (tfm p m)) (p^m)






-- [1, 1, 1] 0 , [0, 1, 1] 1, [2, 0, 1] 0, [1, 0, 1] 0 , [0, 0, 1] 2,
-- [2, 2, 0] 0 , [1, ]

--ff p = 0 : [n + (p-1)*(sum (take n (ff p))) | (n,s) <- zip _N (tail (sff p))]

-- ff2 p = [factors p (fac (3^n)) | n <- _N]

-- [0, 1, 4, ]
-- [0, 1+(p-1)*(0), 2+(p-1)*(0 + 1), 3+(p-1)]
