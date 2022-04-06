class Period:
    def SetTime(self, start_hour, start_min, end_hour, end_min):
        self.__start_hour = start_hour
        self.__start_min = start_min
        self.__end_hour = end_hour
        self.__end_min = end_min
        return
    def SetStart(self, start_hour, start_min):
        self.__start_hour = start_hour
        self.__start_min = start_min
        return
    def SetEnd(self, end_hour, end_min):
        self.__end_hour = end_hour
        self.__end_min = end_min
        return
    def GetTime(self):
        return [self.__start_hour, self.__start_min, self.__end_hour, self.__end_min]
    def GetStart(self):
        return [self.__start_hour, self.__start_min]
    def GetEnd(self):
        return [self.__end_hour, self.__end_min]