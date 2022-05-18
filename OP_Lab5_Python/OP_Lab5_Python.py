from classes import *
from functions import inputNums, outputNums, countSum, findMin

m = int(input("Введіть m (кількість двійкових чисел): "))
n = int(input("Введіть n (кількість вісімкових чисел): "))
print("\n---Початок введення двійкових чисел---\n")
binNums = inputNums(m, 2)
print("\n---Початок введення вісімкових чисел---\n")
octNums = inputNums(n, 8)

print("\n---Введені вами дані---\n")
print("Двійкові числа: ", end = "")
outputNums(binNums)
print("Вісімкові числа: ", end = "")
outputNums(octNums)

sumBins = countSum(binNums, 2)
sumOcts = countSum(octNums, 8)
print("\nСума двійкових чисел: " + str(sumBins.getNumber))
print("Сума вісімкових чисел: " + str(sumOcts.getNumber))
sumOctInBin = TIntNumber2(sumOcts.convertToBase())
print("Отримане значення суми вісімкових чисел у двійковому форматі: " + str(sumOctInBin.getNumber))
findMin(sumBins, sumOctInBin)