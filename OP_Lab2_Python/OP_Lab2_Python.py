#Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця перерви. 
#При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
#Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у черзі, 
#якщо на одного клієнта в середньому витрачається 15 хв.

from functions import *

path = "File.dat"
working_hours = Input_Working_Hours()
work = working_hours.GetTime()
print('Години роботи: ',str(work[0]).zfill(2),':',str(work[1]).zfill(2),' - ',str(work[2]).zfill(2),':',str(work[3]).zfill(2),sep='')
#---#---#---#---#---#---#---#---#---#---#---#---#---#---#
num_of_breaks = int(input('\nВведiть кiлькiсть технiчних перерв у роботi каси: '))
FileOut = open(path,'wb')
num_of_checked_breaks = Output_Breaks_In_File(FileOut,Input_Breaks(num_of_breaks),working_hours,num_of_breaks)
FileOut.close()
#---#---#---#---#---#---#---#---#---#---#---#---#---#---#
FileIn = open(path,'rb')
Output_File_In_Console(FileIn,num_of_checked_breaks)
FileIn.close()
#---#---#---#---#---#---#---#---#---#---#---#---#---#---#
