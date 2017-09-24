class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        length = len(A)
        dpList = [0]
        minusList = []
        answer = 0
        sequencedNum = 1 # the number of sequenced number
        
        if length == 0 or length == 1:
            return 0
        else:
            for i in range(1, length-1):
                dpList += [dpList[i-1]+i]
                
        print(dpList)
            
        for i in range(1, length):
            minusList += [A[i] - A[i-1]]
            
        print(minusList)
        
        for i in range(1, len(minusList)):
            if minusList[i] == minusList[i-1]:
                sequencedNum += 1
                if i == len(minusList) -1:
                    answer += dpList[sequencedNum-1]
                    sequencedNum = 1
                    print("end", answer, i)
            else:
                if sequencedNum == 1:
                    print("hi")
                    continue
                answer += dpList[sequencedNum-1]
                print("end", answer, i, sequencedNum)
                sequencedNum = 1
        
        return answer
            
        
        
        
        