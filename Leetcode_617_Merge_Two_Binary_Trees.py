class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        
        if not t1 and not t2:
            return None;
        if t1:
            t1value = t1.val
            t1Left = t1.left
            t1Right = t1.right
        else:
            t1value = 0
            t1Left = None
            t1Right = None
        if t2:
            t2value = t2.val
            t2Left = t2.left
            t2Right = t2.right
        else:
            t2value = 0
            t2Left = None
            t2Right = None
        answer = TreeNode(t1value+t2value)
        answer.left = self.mergeTrees(t1Left, t2Left)
        answer.right = self.mergeTrees(t1Right, t2Right)
        return answer