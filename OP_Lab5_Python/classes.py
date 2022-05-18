from abc import ABC, abstractmethod
from functions import convertFromDec, convertToDec

class TIntNumber(object):
    def __init__(self, number, base):
        self._number = number
        self._base = base
    def getBase(self):
        return self._base
    def getNum(self):
        return self._number
    def setNum(self, number):
        self._number = number
        return

    @abstractmethod
    def add(self, obj):
        pass
    @abstractmethod
    def compare(self, obj):
        if self._number < obj._number:
            return -1
        elif self._number == obj._number:
           return 0
        else:
           return 1
    @abstractmethod
    def convertToBase(self, base):
        if self.base == 10:
            return convertFromDec(self._number, base)
        elif base == 10:
            return convertToDec(self._number, self._base)
        else:
            return convertFromDec(convertToDec(self._number, self._base), base)
    pass


class TIntNumber2(TIntNumber):
    def __init__ (self, number):
        super().__init__(number, 2)
    def add(self, obj):
        self._number = convertFromDec(convertToDec(self._number, 2) + convertToDec(obj._number, 2), 2)
        return self
    def compare(self, obj):
        super().compare(obj)
    def convertToBase(self, base = 8):
        return super().convertToBase(base)
    pass


class TIntNumber8(TIntNumber):
    def __init__ (self, number):
        super().__init__(number, 8)
    def add(self, obj):
        self._number = convertFromDec(convertToDec(self._number, 8) + convertToDec(obj._number, 8), 8)
        return self
    def compare(self, obj):
        super().compare(obj)
    def convertToBase(self, base = 2):
        return super().convertToBase(base)
    pass