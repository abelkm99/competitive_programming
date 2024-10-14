# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:


        ans: int = 0

        def sol(root: Optional[TreeNode]) -> int:
            nonlocal ans

            if not root:
                return 0
            
            l = sol(root.left)
            r = sol(root.right)

            ans = max(ans, l + r)

            return max(l, r) + 1

        sol(root)
        return ans 
