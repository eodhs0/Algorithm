numOfWord = int(input())

passwords = []
flag = 0

answerWord = ""

for i in range(0, numOfWord):
    passwords.append(str(input()))

for i in range(0, numOfWord):
    for k in range(i, numOfWord):
        if passwords[i] == passwords[k][::-1]:
            flag = 1
            answerWord = passwords[i]
            break
    if flag == 1:
        break

answerlist = []
answerlist += answerWord

midWord = answerlist[int(len(answerlist)/2)]

print(len(answerWord), midWord)


