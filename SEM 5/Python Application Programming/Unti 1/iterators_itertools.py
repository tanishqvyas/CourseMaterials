###################################################
## ITERATORS

## __iter__() : for an iterable to be iterable it should have this

'''
An iterator is an object that can be iterated upon, 
meaning that you can traverse through all the values. ... 
Technically, in Python, an iterator is an object which 
implements the iterator protocol, which consist of the 
methods __iter__() and __next__() .


basically an object with a state.
'''

nums = [1,2,3]

# i_nums = nums.__iter__()
i_nums = iter(nums)

# print(next(i_nums))
# print(next(i_nums))
# print(next(i_nums))
# print(next(i_nums)) # Gives StopIteration Exception since no more vals


# Thus we do something like this to tackle that
while 1:

	try:
		item = next(i_nums)
		print(item)

	except StopIteration:
		break


############ ITERTOOLS ###############

import itertools


### Count
counter = itertools.count()

# One way
print(next(counter))
print(next(counter))
print(next(counter))

# Another way
for num in counter:
	print(num)




# Another Example
data = [100, 200, 300, 400]

# the unavailable values are None
daily_data = list(itertools.zip_longest(range(10), data))


daily_data = list(zip(itertools.count(), data))
print(daily_data)



# Another example
counter = itertools.count(start=5, step=1)
counter1 = itertools.count(start=2, step = -3.5)










### Cycle func
data = [1,2,3,4,5,6,7,8,9]
# this guy just cycles around and goes on infinitely
counter = itertools.cycle(data)


### Repeat
# keeps repeating same shit for times
counter = itertools.repeat(2, times=3)

squares = map(pow, range(10), itertools.repeat(2))
print(list(squares))



### Star map
squares = itertools.starmap(pow, [(0, 2), (1, 2), (3, 2), (4, 2)])
print(list(squares))





##### Most popular Funcs

letters = ["a", "b", "c", "d", "e"]
numbers = [1, 2, 3 ,4]
names = ["cory", "coby", "garret", "tyler", "karl"]

# Get combinations of two values
result = itertools.combinations(letters, 2)
permutes = itertools.permutations(letters, 2)
print(result)
print(permutes)

# 4 digit code (allow repeatetions)
codes = itertools.product(numbers, repeat=4)

codes2 = itertools.combinations_with_replacement(numbers, 4)



# chain the stuff 
# basically it helps us save memory where in traditional method
# we make copies of vars and assign it to new ones n stuff
combined_res = itertools.chain(letters, numbers)

for i in combined_res:
	print(i)


### Slicing stuff

# Slice a range of 10 values 1: start idx, 5 : stop idx, 2 : step count
combined_res = itertools.islice(range(10),1, 5, 2)




#### Iterate over stuff in files without loading entire file in mem
with open("sample.txt", "r") as f:

	# Get first 3 lines
	header = itertools.islice(f, 3)

	for line in header:
		print(line)




#### Compress func

selectors = [True, False, True, True, False]
result = itertools.compress(letters, selectors)
for i in result:
	print(i)


# itertools.filterfalse(testFunc, list)

# itertools.dropwhile
# itertools.takewhile
# itertools.accumulate
# itertools.groupby  # this shit needs sorted input