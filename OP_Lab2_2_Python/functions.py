from Classes import Period
import pickle

#Виведення переліку технічних перерв із файлу у консоль
def Output_File_In_Console(file, n):
    print('\n--- Перелік технічних перерв у роботі каси ---\n')
    a_break = Period()
    file.seek(0,0)
    for i in range(n):
        a_break = pickle.load(file)
        print(str(a_break.start_hour).zfill(2),':',str(a_break.start_min).zfill(2),' - ',
              str(a_break.end_hour).zfill(2),':',str(a_break.end_min).zfill(2),sep='')
    return

#Введення користувачем часу початку та кінця робочого дня каси 
def Input_Working_Hours():
    work = Period()
    work.start_hour,work.start_min = map(int, input('Введіть час початку робочого дня (у форматі гг:хх): ').split(':'))
    work.end_hour,work.end_min = map(int, input('Введіть час кінця робочого дня (у форматі гг:хх): ').split(':'))
    return work

#Введення користувачем переліку технічних перерв і їх збереження у масиві об'єктів
#класу Period
def Input_Breaks(n):
    print('Будь ласка, вводьте перерви у порядку зростання їх початку!\n',
          '\n--- Початок введення перелiку технiчних перерв ---')
    breaks = []
    for i in range (n):
        a_break = Period()
        a_break.start_hour,a_break.start_min = map(int, input('\nВведіть час початку перерви (у форматі гг:хх): ').split(':'))
        a_break.end_hour,a_break.end_min = map(int, input('Введіть час кінця перерви (у форматі гг:хх): ').split(':'))
        breaks.append(a_break)
    return breaks

#Виведення переліку перерв, перевірених на накладання та повторення, у бінарний файл
def Output_Breaks_In_File(file, breaks, work, n):
    m = 0
    for i in range (n):
        flag,breaks[i] = Check_Break(breaks[i],breaks,work,i)
        if flag:
            pickle.dump(breaks[i], file)
            m += 1
    return m

#Перевірка перерв на накладання та чи не виходять вони за межі робочого дня
def Check_Break(a_break:Period, breaks, work, k):
    flag1,a_break = Break_Is_In_Work_Time(a_break,work)
    if not flag1:
        return False, a_break
    for i in range (k):
        flag2,a_break = Breaks_Is_Overlap(breaks[i],a_break)
        if flag2:
            return False, a_break
    return True, a_break

#Перевірка, чи не виходить перерва за межі початку та кінця робочого дня
def Break_Is_In_Work_Time(a_break:Period, work:Period):
    if (a_break.end_hour < work.start_hour or a_break.end_hour == work.start_hour and a_break.end_min <= work.start_min
    or a_break.start_hour > work.end_hour or a_break.start_hour == work.end_hour and a_break.start_min >= work.end_min):
        return False, a_break
    if a_break.start_hour < work.start_hour or a_break.start_hour == work.start_hour and a_break.start_min < work.start_min:
        a_break.start_hour = work.start_hour
        a_break.start_min = work.start_min
    if a_break.end_hour > work.end_hour or a_break.end_hour == work.end_hour and a_break.end_min > work.end_min:
        a_break.end_hour = work.end_hour
        a_break.end_min = work.end_min
    return True, a_break

#Перевірка на накладання та повторення перерв
def Breaks_Is_Overlap(a_break:Period, check_break:Period):
    if ((a_break.start_hour < check_break.start_hour or a_break.start_hour == check_break.start_hour and a_break.start_min <= check_break.start_min)
    and (a_break.end_hour > check_break.end_hour or a_break.end_hour == check_break.end_hour and a_break.end_min >= check_break.end_min)):
        return True, check_break
    if ((a_break.start_hour < check_break.start_hour or a_break.start_hour == check_break.start_hour and a_break.start_min <= check_break.start_min)
    and (a_break.end_hour > check_break.start_hour or a_break.end_hour == check_break.start_hour and a_break.end_min > check_break.start_min)):
        check_break.start_hour = a_break.end_hour
        check_break.start_min = a_break.end_min
    elif ((a_break.end_hour > check_break.end_hour or a_break.end_hour == check_break.end_hour and a_break.end_min >= check_break.end_min)
    and (a_break.start_hour > check_break.start_hour or a_break.start_hour == check_break.start_hour and a_break.start_min > check_break.start_min)):
        check_break.end_hour= a_break.start_hour
        check_break.end_min = a_break.start_min
    return False, check_break

#Обчислення тривалості певного періоду часу
def Count_Duration(period:Period):
    return (period.end_hour * 60 + period.end_min) - (period.start_hour * 60 + period.start_min)

#Перевірка, чи встигне касир обслужити num_of_cust клієнтів за робочий день
def Check_For_Serving_Customers(file, work:Period, num_of_custs, time_for_one_cust, n):
    working_day_duration = Count_Duration(work)
    a_break = Period()
    break_time = 0
    file.seek(0,0)
    for i in range (n):
        a_break = pickle.load(file)
        break_time += Count_Duration(a_break)
    work_time = working_day_duration - break_time
    time_for_customers = time_for_one_cust * num_of_custs
    print('\nЗагальна тривалість робочого дня:',working_day_duration,'хв')
    print('Сумарна тривалiсть перерв:',break_time,'хв')
    print('Робочий час (з урахуванням перерв):',work_time,'хв')
    if work_time >= time_for_customers:
        return True
    return False