data Queue a = Queue [a] [a] deriving (Show)

create :: Queue a 
create = Queue [] []

push :: a -> Queue a -> Queue a
push x (Queue xs ys) = Queue xs (x:ys)



empty :: Queue a -> Bool
empty (Queue a b) = (length a == 0)  && (length b == 0)  

top :: Queue a -> a
top (Queue [] xs) = top $ (Queue (reverse xs) []) 
top (Queue (x:a) b) = x


pop :: Queue a -> Queue a

pop (Queue [] xs) = pop (Queue (reverse xs) [])
pop (Queue (x:a) b) = (Queue a b)



instance Eq a => Eq (Queue a) 
	where
		(Queue x1s y1s) == (Queue x2s y2s) = x1s ++ (reverse y1s) == x2s ++ (reverse y2s)
