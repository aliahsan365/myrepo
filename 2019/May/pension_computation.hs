data Avi = Avi {
    nom :: [Char],
    edat :: Int,
    despeses :: [Int]
    } deriving (Show)

--ejercicio auto-explicativo.
--apartado 1
promigDespeses :: Avi -> Int 
promigDespeses a = round  ((fromIntegral  (sum xs))/(fromIntegral (length xs)))
	where
		xs = despeses a

--apartado 2
edatsExtremes :: [Avi] -> (Int, Int)
edatsExtremes avis = ((minimum xs), (maximum xs))
	where
		xs = map edat avis 
--apartado 3
sumaPromig :: [Avi] -> Int
sumaPromig lavis = foldl (+) 0 (map promigDespeses lavis) 


--apartado 4
maximPromig :: [Avi] -> Int
maximPromig lavis = maximum (map promigDespeses lavis) 

--apartado 5
despesaPromigSuperior :: [Avi] -> Int -> ([Char], Int)
despesaPromigSuperior [] _ = ("",0)
despesaPromigSuperior (a:as) despesa
	|promigDespeses  a >= despesa = (nom a, edat a)
	|otherwise  =  despesaPromigSuperior as despesa  
		



