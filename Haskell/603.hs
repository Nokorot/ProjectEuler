
sqrt' n = floor (sqrt (fromIntegral n))
primesA = 2 : [x | x <- [3,5..], not (any (\y -> mod x y == 0) (takeWhile (<= sqrt' x)  primesA))]


merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = x : y : merge xs ys

_s stream = redR stream
  where redL [] = []
        redL st = st : (redL (tail st))
        redR [] = []
        redR st = st : (merge (redR (init st)) (redL (tail st)))

_S stream = redR (show stream)
  where redL [] = 0
        redL st = (read st :: Integer) + (redL (tail st))
        redR [] = 0
        redR st = (read st :: Integer) + (redR (init st)) +  (redL (tail st))

_P n = take n primesA
