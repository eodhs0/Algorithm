class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target in nums:
            return nums.index(target)
        else:
            minNum = min(nums)
            maxNum = max(nums)
            mid = nums[len(nums)/2]
            if target < minNum:
                return 0
            elif target > maxNum:
                return len(nums)
            else:
                if target <= mid:
                    for i in range(0, nums.index(mid)+1):
                        if nums[i] > target:
                            return i
                else:
                    for i in range(nums.index(mid), len(nums)):
                        if nums[i] > target:
                            return i