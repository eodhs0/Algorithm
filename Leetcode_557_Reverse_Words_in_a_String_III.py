class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        splitList = s.split(" ")
        reverseList = []
        answer = ""
        
        for i in range(0, len(splitList)):
            reverseList += [splitList[i][::-1]]
            
        for i in range(0, len(splitList)):
            answer += reverseList[i]
            if i != len(splitList)-1:
                answer += " "
        
        print(answer)
        return answer