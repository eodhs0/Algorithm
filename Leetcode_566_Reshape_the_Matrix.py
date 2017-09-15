class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        rowLen = len(nums)
        colLen = len(nums[0])
        tempArr = []
        addArr = []
        ansArr = []
        
        if rowLen * colLen == r * c:
            for i in range(0, rowLen):
                for j in range(0, colLen):
                    tempArr += [nums[i][j]]
            idx = 0
            for k in range(0, r):
                for m in range(0, c):
                    addArr += [tempArr[idx]]
                    idx+=1
                ansArr += [addArr]
                addArr = []
            return ansArr
        else:
            return nums
        