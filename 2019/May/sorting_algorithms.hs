
--al estar ordenada si el la el primero es mayor que nuestro elemento
--entonces, se anyade en en el orden de e:x:xs

--apatado 1
insert :: [Int] -> Int -> [Int]
insert [] e = [e]
insert (x:xs) e
	| x > e = e:x:xs 
	|otherwise = x:insert xs e

isort :: [Int] -> [Int]
isort [] = []
isort (x:xs) = insert isl x
	where
		isl = isort xs
-- isl is the tail of the original list, which is sorted already.

--apartado 2
remove :: [Int] -> Int -> [Int]
remove [] _ = []
remove (y:ys) e
	| y == e = ys
	| otherwise = y:remove ys e 

ssort :: [Int] -> [Int]
ssort [] = []
ssort (x:xs)= insert sssorted x
	where
		sssorted = ssort (remove l x)
			where
				l = (x:xs) 

--apartado 3

--Merge of two list that are sorted already.
merge :: [Int] -> [Int] -> [Int]
merge [] [] = []
merge l1 [] = l1
merge [] l2 = l2
merge (x:xs) (y:ys)
	| x <= y = x:(merge xs (y:ys))
	| otherwise = y:(merge (x:xs) ys)

msort :: [Int] -> [Int] 
msort [] = []
msort [uno] = [uno]
msort l = merge (msort (take n l)) (msort (drop n l))
	where
		n = div (length l) 2

--apartado 4
qsort :: [Int] -> [Int]
qsort [] = []
qsort (p:xs) = (qsort menores)  ++ [p] ++ (qsort mayores)
	where
		menores = [x | x <- xs, x <= p]
		mayores = [x | x <- xs ,x > p]

--apartado 5, generalizado
genQsort :: Ord a => [a] -> [a]
genQsort []     = []
genQsort (p:xs) = (genQsort menors) ++ [p] ++ (genQsort majors)
    where
        menors = [x | x <- xs, x <  p]      -- filter (<  p) xs
        majors = [x | x <- xs, x >= p]      -- filter (>= p) xs


















