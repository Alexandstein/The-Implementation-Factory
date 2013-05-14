import random

#Array to be sorted
array = []

def swap(left, right, array):
	temp = array[left]
	array[left] = array[right]
	array[right] = temp

def quicksort(array):
	#Index for sorted subarray.
	pivot = 1
	for pivot in range(1, len(array)):
		cursor = pivot
		while (cursor > 0 and array[cursor] < array[cursor-1]):
			swap(cursor-1, cursor, array)
			cursor -= 1
	
####Start####
#Generate random numbers
numberOfElements = int(raw_input("Enter number of elements to sort: "))

for i in range(0, numberOfElements):
	array.append(random.randint(0,1000))

print(array)
quicksort(array)
print(array)