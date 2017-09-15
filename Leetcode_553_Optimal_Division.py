class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        answer = ""
        if len(nums) == 1:
            answer += str(nums[0])
            return answer
        if len(nums) == 2:
            answer += str(nums[0]) + "/" + str(nums[1])
            return answer
        #nums.sort(reverse=True)
        for i in range(0, len(nums)):
            if i != len(nums) - 1:
                answer += str(nums[i]) + "/"
            else:
                answer += str(nums[i])
            if i == 0:
                answer += "("
            if i == len(nums) - 1:
                answer += ")"
        print(answer)
        return answer