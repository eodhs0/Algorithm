# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.lowestLeft = 0
        self.val = None
        self.findLowestLeft(root, 1)
        return self.val
        
    def findLowestLeft(self, root, level):
        if not root:
            return
        if self.lowestLeft < level:
            self.lowestLeft = level
            self.val = root.val
        self.findLowestLeft(root.left, level+1)
        self.findLowestLeft(root.right, level+1)