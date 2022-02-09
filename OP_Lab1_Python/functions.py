# Створення текстового файлу з текстом, введеним користувачем з клавіатури.
def creating_first_file(path):
    with open(path,'wt') as FstFile:
        while True:
            Text = input()
            for letter in Text:
                if ord(letter) >= 32:
                    FstFile.write(letter)
                else:
                    return
            FstFile.write('\n')
    pass
# Створення нового текстового файлу, що складається з рядків вихідного файлу, у яких вилучені 
# всі двосимвольні слова, а в кінці дописана кількість вилучених слів.
def deleting_2_symb_words(path1,path2):
    Count = 0
    with open(path1,'rt',encoding = 'cp1251') as FstFile, open(path2,'wt') as SndFile:
        while True:
            Text = (FstFile.readline())
            if not Text:
                break
            Text = Text.replace('\n','')
            k = 0
            while k < len(Text):
                m = Text.find(' ',k)
                if m == k:
                    k += 1
                else:
                    if m == -1:
                        m = len(Text)
                    word = Text[k:m]
                    if len(word) == 2:
                        Count += 1
                        if k == 0 and m == len(Text):
                            Text = Text.replace(Text,'',1)
                        elif m != len(Text):
                            Text = Text.replace(Text[0:m + 1],Text[0:k],1)
                        else:
                            Text = Text.replace(Text[0:m],Text[0:k - 1],1)
                    else:
                        k = m + 1
            SndFile.write(Text + '\n')
        SndFile.write('Кількість вилучених слів: ' + str(Count))
    pass
# Виведення змісту файлу в консоль.
def output_file(path):
    with open(path,'rt',encoding = 'cp1251') as File:
        while True:
            Text = File.readline()
            if not Text:
                break
            print(Text,end = '')
    pass
