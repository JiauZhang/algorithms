'''
	For more information see <https://github.com/JiauZhang/algorithms>
'''

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        sum = 0

        def do_convert(root):
            nonlocal sum
            if root.right:
                do_convert(root.right)
            
            root.val = sum + root.val
            sum = root.val

            if root.left:
                do_convert(root.left)
        
        if root:
            do_convert(root)
        
        return root