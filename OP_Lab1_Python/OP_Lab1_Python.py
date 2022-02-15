"""Створити текстовий файл. Сформувати новий текстовий файл, що
складається з рядків вихідного файлу, у яких вилучені всі двосимвольні слова.
Визначити і дописати в кінець нового файлу кількість вилучених слів.
Вивести вміст вихідного і створеного файлів."""

from functions import *
path1 = 'FirstFile.txt'
path2 = 'SecondFile.txt'

with open(path1,'wt') as FirstFileOut:
    print('Введіть ваш текст:')
    creating_first_file(FirstFileOut)

with open(path1,'rt',encoding = 'cp1251') as FirstFileIn1, open(path2,'wt') as SecondFileOut:
    Num = deleting_2_symb_words(FirstFileIn1,SecondFileOut)

with open(path2,'at',encoding = 'cp1251') as SecondFileApp:
    add_num_of_del_words(SecondFileApp,Num)

with open(path1,'rt',encoding = 'cp1251') as FirstFileIn2:
    print('\nВихідний файл:')
    output_file(FirstFileIn2)

with open(path2,'rt',encoding = 'cp1251') as SecondFileIn:
    print('\n\nСтворений файл:')
    output_file(SecondFileIn)
print('\n')