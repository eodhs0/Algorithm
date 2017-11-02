numberList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

a = input()

for i in a:
    if int(i) == 6 or int(i) == 9:
        if int(numberList[6]) < int(numberList[9]):
            numberList[6] += 1
        elif int(numberList[6]) > int(numberList[9]):
            numberList[9] += 1
        else:
            numberList[6] += 1
    else:
        numberList[int(i)] += 1
print(max(numberList))