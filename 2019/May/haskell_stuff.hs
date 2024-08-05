--ex1
-- recursividad con ventanas de dos en dos s = x:y:..., y casos base.
--										         x:y:...
--                                                 x:y:...
svalue :: Char -> Int
svalue 'I' = 1
svalue 'V' = 5
svalue 'X' = 10
svalue 'L' = 50
svalue 'C' = 100
svalue 'D' = 500
svalue 'M' = 1000
svalue '0' = 0
-- el 0 es solamente para hacer el apartado 2.
-- para el apartado 1 se puede quitar (no influye).
		 

		 		 
roman2int :: String -> Int
roman2int [] = 0
roman2int [x] = svalue x
roman2int (x:y:cola) 
		| (svalue x) < (svalue y) = (0-(svalue x)) + roman2int (y:cola)
		| otherwise = svalue x + roman2int (y:cola)

--ex2
--obtenemos  los pares de (act,next) usando zip,s,cola de s, y marca.
--sumamos usando el foldl mappeando los valores usando svalue. 
roman2int' :: String -> Int
roman2int' s = foldl f 0 (zip s (tail (s++"0")))
f n (x,y) 
	| (svalue x) < (svalue y) =  n - svalue x
	| otherwise = n + svalue x 



--apartat 3
--x es lo de ahora
--n es lo anterior x , f x , f f x , f f f x, ....
arrels :: Float -> [Float]
arrels x = iterate f x
	where
		 f n = 0.5*(n+(x/n))

-- apartado 4
--calculamos inifinitamente errores con infinitas parejas de raices de x.
--todas las que no cumplan con el limite de nuestro error no entran en la lista
--a la que se alcanze el error o se suepere, aceptamos y devolvemos
--la aproximacion actual del par (ant,act) (por eso el snd)
arrel :: Float -> Float -> Float
arrel x epsilon =   snd (head (dropWhile p pares))
	where
		pares = zip (arrels x) (tail (arrels x))
		p (xant,xact) = (abs (xant-xact)) > epsilon


data LTree a = Leaf a | Node (LTree a) (LTree a)

--apatado 5
--volver a implementar la funcion show de la clase show orienta a printar
--los LTrees exactamente como los queremos nosotros
instance Show a => Show (LTree a) where
	show (Leaf a) = "{" ++ (show $ a) ++ "}"
	show (Node a1 a2) = "<" ++ (show $ a1) ++ "," ++ (show $ a2) ++ ">"		

--apartado 6
izquierda :: Int -> Int
izquierda x 
	| even x = x `div` 2
	| otherwise = (x `div` 2) + 1

--hay los mismos elementos tanto a la iz, como o la drecha.O hay como mucho un elemento
--mas a la iz. 
build :: [a] -> LTree a
build [x] = (Leaf x)
build l = Node (build (take n l)) (build (drop n l)) 
	where
		 n =  izquierda (length l)

--apartado  7
zipLTrees :: LTree a -> LTree b -> Maybe (LTree (a,b))
-- devolvemos un tipo LTree con tupla y encapsulado.
zipLTrees (Leaf a) (Leaf b) = Just (Leaf(a,b))
zipLTrees (Node ti td) (Node  ui ud) = do 
	a <- zipLTrees ti ui
	b <- zipLTrees td ud
	return (Node a b)
-- Nothing _ = Nothing
zipLTrees _ _ = Nothing	

















