import classes
from functions import inputNums, outputNums

m = int(input("Введіть m (кількість двійкових чисел): "))
n = int(input("Введіть n (кількість вісімкових чисел): "))
print("\n---Початок введення двійкових чисел---\n")
binNums = inputNums(m, 2)
print("\n---Початок введення вісімкових чисел---\n")
octNums = inputNums(n, 8)
print("\n---Введені вами дані---\n")
outputNums(binNums)
outputNums(octNums)