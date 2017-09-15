class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        
        add = 0
        
        for i in range(0, len(nums)):
            if i%2 != 0:
                continue
            else:
                add += min(nums[i], nums[i+1])
            
        return add