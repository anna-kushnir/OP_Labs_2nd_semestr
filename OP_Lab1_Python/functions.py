def creating_first_file(path):
    FstFile = open(path,'wt')
    try:
        while True:
            Text = input()
            for letter in Text:
                if ord(letter) >= 32:
                    FstFile.write(letter)
                else:
                    return
            FstFile.write('\n')
    finally:
        FstFile.close()

