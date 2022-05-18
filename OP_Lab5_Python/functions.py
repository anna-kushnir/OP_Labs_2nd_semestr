import classes

def isNumeralBase(num, base):
    while num:
        if num % 10 < base:
            num = num // 10
        else:
            return False
    return True

def convertFromDec(dec, base):
    num = 0
    i = 0
    while dec > base - 1:
        num += (dec % base) * 10**i
        i += 1
        dec = dec // base
    return num + dec * 10**i

def convertToDec(num, base):
    dec = 0
    i = 0
    while num:
        dec += (num % 10) * base**i
        i += 1
        num = num // 10
    return dec

def inputNums(k, base):
    if base == 2:
       obj= TIntNumber2(0)
    elif base == 8:
        obj = TIntNumber8(0)
    else:
        obj = TIntNumber(0, base)
    nums = []
    for i in range (k):
        num = int(input("Введіть число:"))
        if isNumeralBase(num, base):
            obj.setNum(num)
            nums = nums + obj
        else:
            print("Ви ввели некоректне число! Спробуйте ще раз!")
            i -= 1
    return nums

def outputNums(nums):
    for i in range (0, nums.size(), 1):
        print(nums[i], end = " ")
    return

def countSum(nums : list, base):
    if base == 2:
        sum = TIntNumber2(0)
    elif base == 8:
        sum = TIntNumber8(0)
    else:
        sum = TIntNumber(0, base)
    for i in range (0, nums.size(), 1):
        sum.add(nums[i])
    return sum

