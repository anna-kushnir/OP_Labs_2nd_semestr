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