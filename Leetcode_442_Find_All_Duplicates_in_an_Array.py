class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ansArr = []
        
        nums.sort()
        save = 0
        
        for i in range(0, len(nums)-1):
            if nums[i] == nums[i+1]:
                ansArr += [nums[i]]
        
        return ansArr