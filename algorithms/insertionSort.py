import random

def insertionSort(array):
	#Index for sorted subarray.
	pivot = 1
	for pivot in range(1, len(array)):
		cursor = pivot
		while (cursor > 0 and array[cursor] < array[cursor-1]):
			array[cursor-1], array[cursor] = array[cursor], array[cursor-1]
			cursor -= 1
	
####driver####
#Array to be sorted
array = []

#Generate random numbers
numberOfElements = int(raw_input("Enter integer number of elements to sort: "))

for i in range(0, numberOfElements):
	array.append(random.randint(0,1000))

print(array)
insertionSort(array)
print(array)