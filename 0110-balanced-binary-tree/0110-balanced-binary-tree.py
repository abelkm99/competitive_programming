# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode], ans: bool = True) -> bool:

        def sol(root: TreeNode | None) -> tuple[int, bool]:
            if not root:
                return 0, True
        
            lc = sol(root.left)
            rc = sol(root.right)


            return (max(lc[0], rc[0]) + 1), lc[1] and rc[1] and abs(rc[0] - lc[0]) <= 1

        return sol(root)[1]