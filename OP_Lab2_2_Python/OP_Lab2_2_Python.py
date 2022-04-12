#Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця перерви. 
#При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
#Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у черзі, 
#якщо на одного клієнта в середньому витрачається 15 хв.

from functions import *

path = "File.dat"
working_hours = Input_Working_Hours()
num_of_breaks = int(input('\nВведiть кiлькiсть технiчних перерв у роботi каси: '))
FileOut = open(path,'wb')
num_of_checked_breaks = Output_Breaks_In_File(FileOut,Input_Breaks(num_of_breaks),working_hours,num_of_breaks)
FileOut.close()

FileIn = open(path,'rb')
work = working_hours.GetTime()
print('\nГодини роботи: ',str(work[0]).zfill(2),':',str(work[1]).zfill(2),' - ',str(work[2]).zfill(2),':',str(work[3]).zfill(2),sep='')
Output_File_In_Console(FileIn,num_of_checked_breaks)

time_for_one_customer = 15
N = int(input('\nВведiть кiлькiсть клiєнтiв, що стоять у черзi: '))
if Check_For_Serving_Customers(FileIn, working_hours, N, time_for_one_customer,num_of_checked_breaks):
	print('\nКасир встигне обслужити',N,'клiєнтiв за робочий день')
else:
	print('\nКасир НЕ встигне обслужити',N,'клiєнтiв за робочий день')
FileIn.close()