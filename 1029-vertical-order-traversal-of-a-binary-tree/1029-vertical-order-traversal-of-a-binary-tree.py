# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:

        memo = defaultdict(list)
        def dfs(node:Optional[TreeNode], h:int, v:int) -> None:
            if not node:
                return
            memo[h].append((v, node.val))
            dfs(node.left, h - 1, v + 1)
            dfs(node.right, h + 1,v + 1)
        
        dfs(root, 0, 0)

        # print(memo)

        ans = [None] * len(memo.keys())
        mn = abs(min(memo.keys()))
        for k, v in memo.items():
            v.sort()
            # print(k + mn, v)
            ans[k + mn] = [x for _, x in v]
        return ans
            