from abc import ABC, abstractmethod
from converting import convertFromDec, convertToDec

class TIntNumber(ABC):
    def __init__(self, number = 0, base = 10):
        self.__number = number
        self.__base = base
    @property
    def getBase(self):
        return self.__base
    @property
    def getNumber(self):
        return self.__number

    @abstractmethod
    def add(self, obj : 'TIntNumber'):
        pass
    @abstractmethod
    def compare(self, obj : 'TIntNumber'):
        if self.__number < obj.__number:
            return -1
        elif self.__number == obj.__number:
           return 0
        else:
           return 1
    @abstractmethod
    def convertToBase(self, base):
        if self.__base == 10:
            return convertFromDec(self.__number, base)
        elif base == 10:
            return convertToDec(self.__number, self.__base)
        else:
            return convertFromDec(convertToDec(self.__number, self.__base), base)
    pass


class TIntNumber2(TIntNumber):
    def __init__ (self, number = 0):
        super().__init__(number, 2)
    def add(self, obj : 'TIntNumber2'):
        sum = TIntNumber2(convertFromDec(convertToDec(self.getNumber, 2) + convertToDec(obj.getNumber, 2), 2))
        return sum
    def compare(self, obj : 'TIntNumber2'):
        return super().compare(obj)
    def convertToBase(self, base = 8):
        return super().convertToBase(base)
    pass


class TIntNumber8(TIntNumber):
    def __init__ (self, number = 0):
        super().__init__(number, 8)
    def add(self, obj : 'TIntNumber8'):
        sum = TIntNumber8(convertFromDec(convertToDec(self.getNumber, 8) + convertToDec(obj.getNumber, 8), 8))
        return sum
    def compare(self, obj : 'TIntNumber8'):
        return super().compare(obj)
    def convertToBase(self, base = 2):
        return super().convertToBase(base)
    pass