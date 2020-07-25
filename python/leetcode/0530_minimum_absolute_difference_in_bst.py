'''
	> Base Repo --> https://github.com/JiauZhang/algorithms
'''

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        res = sys.maxsize
        prev = -1

        def LDR(root: TreeNode):
            nonlocal res, prev
            if root.left:
                LDR(root.left)
            
            if prev != -1:
                tmp = root.val - prev
                res = min(tmp, res)
            
            prev = root.val

            if root.right:
                LDR(root.right)
        
        LDR(root)

        return res