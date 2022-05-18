from classes import *

def isNumeralBase(num, base):
    while num:
        if num % 10 < base:
            num = num // 10
        else:
            return False
    return True

def inputNums(k, base):
    nums = []
    i = 0
    while i < k:
        num = int(input("Введіть число: "))
        if isNumeralBase(num, base):
            if base == 2:
                obj = TIntNumber2(num)
            elif base == 8:
                obj = TIntNumber8(num)
            else:
                continue
            nums.append(obj)
        else:
            print("Ви ввели некоректне число! Спробуйте ще раз!")
            i -= 1
        i += 1
    return nums

def outputNums(nums):
    for i in range (0, len(nums), 1):
        print(nums[i].getNumber, end = " ")
    print()
    return

def countSum(nums, base):
    if base == 2:
        sum = TIntNumber2()
    elif base == 8:
        sum = TIntNumber8()
    else:
        return 0
    for i in range (0, len(nums), 1):
        sum = sum.add(nums[i])
    return sum

def findMin(bins : TIntNumber2, octs : TIntNumber2):
    flag = bins.compare(octs)
    if flag < 0:
        print("\nСума двійкових чисел менша, ніж вісімкових")
    elif flag == 0:
        print("\nСуми двійкових та вісімкових чисел рівні")
    else:
        print("\nСума вісімкових чисел менша, ніж двійкових")
    return
