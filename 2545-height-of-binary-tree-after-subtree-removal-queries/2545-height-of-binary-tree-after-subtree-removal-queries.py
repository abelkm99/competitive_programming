# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:

        dp = {}
        ans = {}

        def dfs(node: TreeNode | None) -> int:
            if not node:
                return 0
            
            l = dfs(node.left)
            r = dfs(node.right)
            dp[node.val] = (l, r)

            return max(l, r) + 1
        
        def compute(node: TreeNode, level: int, bound: int) -> None:
            if node.left:
                ans[node.left.val] = max(dp[node.val][1] + level, bound)
                compute(node.left, level + 1, ans[node.left.val])
            if node.right:
                ans[node.right.val] = max(dp[node.val][0] + level, bound)
                compute(node.right, level + 1, ans[node.right.val])
        dfs(root)
        compute(root, 0, float("-inf"))
        
        return [ans[q] for q in queries]