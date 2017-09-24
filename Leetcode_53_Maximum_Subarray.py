class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        answer = -999999999999
        sumNumber = 0
        for i in range(0, len(nums)):
            sumNumber = max(sumNumber, 0) + nums[i]
            answer = max(answer, sumNumber)
            
        return answer