class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        flagList = []
        ansList = []
        listLength = len(nums)
        
        for i in range(0, listLength):
            flagList += [0]
          
        if len(nums) == 0:
            return nums
        
        nums = list(set(nums))
        
        for i in range(0, len(nums)):
            flagList[nums[i]-1] = 1
        
        for i in range(0, listLength):
            if flagList[i] == 0:
                ansList += [i+1]
        return ansList
        
        
        