"""Створити текстовий файл. Сформувати новий текстовий файл, що
складається з рядків вихідного файлу, у яких вилучені всі двосимвольні слова.
Визначити і дописати в кінець нового файлу кількість вилучених слів.
Вивести вміст вихідного і створеного файлів."""

from functions import *
path1 = 'FirstFile.txt'
path2 = 'SecondFile.txt'
print('Введіть ваш текст:')
creating_first_file(path1)
deleting_2_symb_words(path1,path2)
print('\nВихідний файл:')
output_file(path1)
print('\n\nСтворений файл:')
output_file(path2)
print('\n')