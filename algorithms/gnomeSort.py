####Gnome sort####
def gnomeSort(array):
	for index in range(0, len(array)):
		while index > 0 and (array[index] < array[index-1]):
			array[index], array[index-1] = array[index-1], array[index]
			index -= 1
			
####driver####
import random

#Array to be sorted
array = []

#Generate random numbers
numberOfElements = int(raw_input("Enter integer number of elements to sort: "))

for i in range(0, numberOfElements):
	array.append(random.randint(0,1000))

print(array)
gnomeSort(array)
print(array)