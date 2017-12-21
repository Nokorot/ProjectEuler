import Data.List.Split
import Debug.Trace

asInt = (\x -> read x :: Int)

-- Problem 15
nPr n 0 = 1
nPr n r = n * (nPr (n-1) (r-1))
nCr n r = div (nPr n r) (nPr r r)

p15 = nCr 40 20

-- Problem 16
p16 = sum (map (\x -> read [x] :: Int) (show (2^1000)))

-- Problem 18
input17 = "75,95 64,17 47 82,18 35 87 10,20 04 82 47 65,19 01 23 75 03 34,88 02 77 73 07 63 67,99 65 04 28 06 16 70 92,41 41 26 56 83 40 80 70 33,41 48 72 33 47 32 37 16 94 29,53 71 44 65 25 43 91 52 97 51 14,70 11 33 28 77 73 17 78 39 68 17 57,91 71 52 38 17 14 91 43 58 50 27 29 48,63 66 04 68 89 53 67 30 73 16 69 87 40 31,04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"
x17 = (map (\x -> map asInt (splitOn " " x)) (splitOn "," input17))

maxTot [x] = head x
maxTot (x:xs) = (head x) + (max (maxTot xs) (maxTot (map tail xs)))

-- Problem 20
fac 0 = 1
fac n = fac (n-1) * n

p20 = sum (map (\x -> read [x] :: Int) (show (fac 100)))


-- Problem 31

--x:xs [2,4,10,40,100,200]


--[[],[],[]]

merge :: [a] -> [a] -> [a]
merge xs     []     = xs
merge []     ys     = ys
merge (x:xs) (y:ys) = x : y : merge xs ys

add' elm [] = [elm]
add' elm (x:xs)
    | x == elm = x:xs
    | x < elm = x : add' elm xs
    | otherwise = elm : x : xs

elem' elm [] = False
elem' elm (x:xs)
    | x == elm = True
    | x > elm = False
    | otherwise = elem' elm xs

func [] = [[]]

func (x:xs) = [a:as | a<-[0..x], as<-(func xs)]

pValue = [200, 100, 50, 20, 10, 5, 2, 1]
a31 = func (map (div 200) pValue)
p31 = filter (\coins -> 200 == sum (map (\(x,y) -> x*y) (zip pValue coins))) a31

patterens = [
--  [ 1, 2, 5,10,20,50,100,200]
    [-2, 1, 0, 0, 0, 0, 0, 0],
    [-1,-2, 1, 0, 0, 0, 0, 0],
    [ 0, 0,-2, 1, 0, 0, 0, 0],
    [ 0, 0, 0,-2, 1, 0, 0, 0],
    [ 0, 0, 0,-1,-2, 1, 0, 0],
    [ 0, 0, 0, 0, 0,-2, 1, 0],
    [ 0, 0, 0, 0, 0, 0,-2, 1]]

changeX mem coins _ [] = mem
changeX mem coins (x:xs) (p:ps)
    | all (0<=) rcoins && not (elem rcoins mem) = changeX (rechange rcoins) coins xs ps
    | otherwise = (changeX mem coins xs ps)
  where rcoins = (map (\(x,y) -> x+y) (zip coins p))
        rechange coins = changeX (coins:mem) coins coins patterens


-- [a,b,c,d,e,f] -> [[],[],[]]
change coins = changeX [coins] coins coins patterens

q31 = length (change [200,0,0,0,0,0,0,0])

-- Problem 45

tNr = [div (n*(n+1)) 2   | n <- [1..]]
pNr = [div (n*(3*n-1)) 2 | n <- [1..]]
hNr = [n*(2*n-1)   | n <- [1..]]

getEqual (i,j,k) (x:xs) (y:ys) (z:zs)
    | x == y && y == z = (x, (i,j,k)) : getEqual (i+1,j+1,k+1) xs ys zs
    | m == x = getEqual (i+1,j,k) xs (y:ys) (z:zs)
    | m == y = getEqual (i,j+1,k) (x:xs) ys (z:zs)
    | m == z = getEqual (i,j,k+1) (x:xs) (y:ys) zs
    where m = minimum [x,y,z]

p45 = (getEqual (1,1,1) tNr pNr hNr) !! 2

-- Problem 46


sqrt' n = floor (sqrt (fromIntegral n))
primesA = 2 : [x | x <- [3,5..], not (any (\y -> mod x y == 0) (takeWhile (<= sqrt' x)  primesA))]

isPrime p = func p primesA
    where func p (x:xs)
                | mod p x == 0 = False
                | sqrt' p < x  = True
                | otherwise = func p xs

primeSquare m = filter (\(x,y) -> isPrime x) [(m-2*x^2,x) | x<-(takeWhile (<= (sqrt' (div m 2)) ) [1..]) ]

first func (x:xs)
    | func x = x
    | otherwise = first func xs

p46 = first (\x-> 0 == length (primeSquare x)) (filter (\x-> not (isPrime x)) [3,5..])


-- Problem 48

selfPower n = func n n
    where func x 1 = x
          func 0 p = 0
          func x p
              | 0 == (mod p 2) = func (mod (x*x) (10^10)) (div p 2)
              | otherwise    = mod (x * (func x (p-1))) (10^10)
p48 = mod (sum (map selfPower [1..1000])) (10^10)

-- Problem 49

primes49 = takeWhile (<10000) (dropWhile (<1000) primesA)
aretmeticPrimes = [[x, y, 2*y-x] | x <- primes49, y <- (dropWhile (<= x) primes49), elem (2*y-x) primes49]

isPertobations [x] = True
isPertobations (x:xs) = if func (show x) (show (head xs))
                        then isPertobations xs
                        else False
                        where func a b = (all (`elem` a) b) and (all (`elem` a) b)


p49 = filter isPertobations aretmeticPrimes
