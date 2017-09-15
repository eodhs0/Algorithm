class Solution:
      def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        #3,2,1,6,0,5
        answerArray = []
        
        maxIndex = 0
        leftMax = 0
        rightMax = 0
        leftMaxIndex = 0
        rightMaxIndex = 0

        def solve(node, nums):
            index = nums.index(max(nums))
            leftArr = nums[:index]
            rightArr = nums[index+1:]
            if leftArr:
                node.left = TreeNode(max(leftArr))
                solve(node.left, leftArr)
            if rightArr:
                node.right = TreeNode(max(rightArr))
                solve(node.right, rightArr)
                
        root = TreeNode(max(nums))
        solve(root, nums)
        
        print(root)
        
        return root