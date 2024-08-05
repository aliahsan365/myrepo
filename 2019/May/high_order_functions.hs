
--ex1
countIf :: (Int -> Bool) -> [Int] -> Int
countIf p l = length $ filter p l

--ex2
pam :: [Int] -> [Int -> Int] -> [[Int]]
pam l fl = map (\f -> map f l) fl

--version alternativa de pam
--pam' :: [Int] -> [Int -> Int] -> [[Int]]
--pam' l fl = [map f l| f <- fl]

--ex3
--En un map lo que hacemos implicitamente es usar la funcion aplicacion $
-- En este caso lo parametros esta girados y es por eso que conviene hacer un flip
pam2 :: [Int] -> [Int -> Int] -> [[Int]]
pam2 l fl = [map (flip ($) x) fl | x <- l]

--ex4
filterFoldl :: (Int -> Bool) -> (Int -> Int -> Int) -> Int -> [Int] -> Int
filterFoldl p f ini l = foldl f ini $ filter p l

--ex5
--insert (<) [1,4,6,9,12] 8
insert :: (Int -> Int -> Bool) -> [Int] -> Int -> [Int]
insert _ [] i = [i]
insert p (x:xs) i
	|not(p i x) == True = x:insert p xs i
	|otherwise = i:x:xs
		
insertionSort :: (Int -> Int -> Bool) -> [Int] -> [Int]
insertionSort  p l  = foldl f [] l
	where
		f = insert p   












