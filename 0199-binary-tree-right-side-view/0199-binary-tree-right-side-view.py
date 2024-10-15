# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        ans: list[int] = []

        def solve(root: TreeNode | None, depth: int, ans: list[int]):
            if not root :
                return
            if len(ans) <= depth:
                ans.append(root.val)
            solve(root.right, depth + 1, ans)
            solve(root.left, depth + 1, ans)
            
            return
        
        solve(root, 0, ans)
        return ans