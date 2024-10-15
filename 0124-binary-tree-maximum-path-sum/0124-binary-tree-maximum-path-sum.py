# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        ans = float("-inf")

        def DFS(root: TreeNode | None):
            nonlocal ans

            if not root:
                return 0
    
            l = DFS(root.left)
            r = DFS(root.right) 
            c = root.val

            ans = max(ans, l + r + c, l + c, r + c, c)
            return max(l + c, r + c, c)
        
        DFS(root)

        return ans