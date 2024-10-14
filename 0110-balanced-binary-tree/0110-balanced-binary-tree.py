# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode], ans: bool = True) -> bool:


        ans = True

        def sol(root):
            nonlocal ans
            if not root:
                return 0
        
        
            lc = sol(root.left)
            rc = sol(root.right)

            if abs(lc - rc) > 1:
                ans = False
        
            return max(lc, rc) + 1
            
        sol(root)

        return ans