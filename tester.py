import os
flag=True
while flag:
    os.system("python3 gerador.py >input")
    os.system("./d < input > outputoriginal")
    os.system("./d2 < input > outputbrute")
    lnumbers = open("outputoriginal", 'r')
    brutet = open("outputbrute", 'r')
    if lnumbers.readlines() == brutet.readlines():
        print("ate agora ta certo")
    else:
        print("deu ruim")
        flag=False
