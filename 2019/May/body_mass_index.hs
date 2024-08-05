bmi :: Float -> Float  -> String
bmi m h  
	| bmi < 18.0 = "underweight"
	| bmi >= 18.0 && bmi < 25.0 = "normal weight"
	| bmi >= 25.0 && bmi < 30 = "overweight"
	| bmi >= 30 && bmi < 40 = "obese"
	| bmi >=  40 = "severely obese"
	where bmi = m  / (h * h)  

	
tratando ::  String -> String
tratando linea = bmi peso altura
	where
		peso = (read $ head $ tail $ words linea :: Float)
		altura = (read $ last $ words linea ::  Float) 

main = do
    line <- getLine
    if line /= "*" then do
        putStrLn $ (head $ words line ) ++ ": " ++ (tratando line)
        main
    else
        return ()




