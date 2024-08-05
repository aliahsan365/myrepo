
from functools import reduce





def evens_product(l):
    return reduce((lambda acc,x: acc * x),filter((lambda x:True if (x%2 == 0) else False),l),1)


#print(evens_product([1,2,4,3]))


