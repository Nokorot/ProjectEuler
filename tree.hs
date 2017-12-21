
data Tree a = Nil
            | Node a (Tree a) (Tree a)
            deriving (Eq, Ord, Show, Read)


--add' elm [] = [node (head elm) elm []]


fun x Nil  = Node x Nil Nil
fun x (Node v a b)
    | x == v = Node v a b
    | x < v = Node v (fun x a) b
    | x > v = Node v a (fun x b)

data BTree a = None
             | BNode [a] a [BTree a]
             deriving (Eq, Ord, Show, Read)

branch (BNode a xs) = xs

add' elm tr = func elm elm tr
    where func elm (k:ks) None = [ BNode elm [] ]
          func elm (k:ks) (x : xs)
              | k == b = (func elm ks x ) : xs
              | k <  b = ( BNode elm k None ) : x:xs
              | k >  b = ( x : branch (func elm (k:ks) xs) )
