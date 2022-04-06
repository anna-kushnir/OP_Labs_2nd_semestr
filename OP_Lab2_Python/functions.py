from Classes import Period
import pickle

#Виведення переліку технічних перерв із файлу у консоль
def Output_File_In_Console(file,n):
    print('\n--- Перелік технічних перерв у роботі каси ---\n')
    a_break = Period()
    file.seek(0,0)
    for i in range(n):
        a_break = pickle.load(file)
        a_break = a_break.GetTime()
        print(str(a_break[0]).zfill(2),':',str(a_break[1]).zfill(2),' - ',str(a_break[2]).zfill(2),':',str(a_break[3]).zfill(2),sep='')
    return

#Введення користувачем часу початку та кінця робочого дня каси 
def Input_Working_Hours():
    work = Period()
    hour,min = map(int, input('Введіть час початку робочого дня (у форматі гг:хх): ').split(':'))
    work.SetStart(hour, min)
    hour,min = map(int, input('Введіть час кінця робочого дня (у форматі гг:хх): ').split(':'))
    work.SetEnd(hour, min)
    return work

#Введення користувачем переліку технічних перерв і їх збереження у масиві об'єктів
#класу Period
def Input_Breaks(n):
    print('Будь ласка, вводьте перерви у порядку зростання їх початку!\n',
          '\n--- Початок введення перелiку технiчних перерв ---\n')
    breaks = []
    for i in range (n):
        a_break = Period()
        hour,min = map(int, input('\nВведіть час початку перерви (у форматі гг:хх): ').split(':'))
        a_break.SetStart(hour, min)
        hour,min = map(int, input('Введіть час кінця перерви (у форматі гг:хх): ').split(':'))
        a_break.SetEnd(hour, min)
        breaks.append(a_break)
    return breaks

#Виведення переліку перерв, перевірених на накладання та повторення, у бінарний файл
def Output_Breaks_In_File(file,breaks,work,n):
    m = 0
    for i in range (n):
        flag,breaks[i] = Check_Break(breaks[i],breaks,work,i)
        if flag:
            pickle.dump(breaks[i], file)
            m += 1
    return m

#Перевірка перерв на накладання та чи не виходять вони за межі робочого дня
def Check_Break(a_break:Period,breaks,work,k):
    flag1,a_break = Break_Is_In_Work_Time(a_break,work)
    if not flag1:
        return False, a_break
    for i in range (k):
        flag2,a_break = Breaks_Is_Overlap(breaks[i],a_break)
        if flag2:
            return False, a_break
    return True, a_break

#Перевірка, чи не виходить перерва за межі початку та кінця робочого дня
def Break_Is_In_Work_Time(Break:Period,Work:Period):
    a_break = Break.GetTime()
    work = Work.GetTime()
    if (a_break[2] < work[0] or a_break[2] == work[0] and a_break[3] <= work[1]
    or a_break[0] > work[2] or a_break[0] == work[2] and a_break[1] >= work[3]):
        return False, Break
    if a_break[0] < work[0] or a_break[0] == work[0] and a_break[1] < work[1]:
        a_break[0] = work[0]
        a_break[1] = work[1]
    if a_break[2] > work[2] or a_break[2] == work[2] and a_break[3] > work[3]:
        a_break[2] = work[2]
        a_break[3] = work[3]
    checked_break = Period()
    checked_break.SetTime(a_break[0],a_break[1],a_break[2],a_break[3])
    return True, checked_break

#Перевірка на накладання та повторення перерв
def Breaks_Is_Overlap(Is:Period,Check:Period):
    a_break = Is.GetTime()
    check_break = Check.GetTime()
    if ((a_break[0] < check_break[0] or a_break[0] == check_break[0] and a_break[1] <= check_break[1])
    and (a_break[2] > check_break[2] or a_break[2] == check_break[2] and a_break[3] >= check_break[3])):
        return True, Check
    if ((a_break[0] < check_break[0] or a_break[0] == check_break[0] and a_break[1] <= check_break[1])
    and (a_break[2] > check_break[0] or a_break[2] == check_break[0] and a_break[3] > check_break[1])):
        check_break[0] = a_break[2]
        check_break[1] = a_break[3]
    elif ((a_break[2] > check_break[2] or a_break[2] == check_break[2] and a_break[3] >= check_break[3])
    and (a_break[0] > check_break[0] or a_break[0] == check_break[0] and a_break[1] > check_break[1])):
        check_break[2] = a_break[0]
        check_break[3] = a_break[1]
    checked_break = Period()
    checked_break.SetTime(check_break[0],check_break[1],check_break[2],check_break[3])
    return False, checked_break

