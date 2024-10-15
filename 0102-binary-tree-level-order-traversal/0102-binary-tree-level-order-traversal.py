# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        tmp = defaultdict(list)

        def solve(root, depth):
            if not root:
                return 0
            
            tmp[depth].append(root.val)

            a = solve(root.left, depth + 1)
            b = solve(root.right, depth + 1)
            return max(a, b) + 1
        
        res = solve(root, 0)

        ans = [[] for _ in range(res)]
        for k, v in tmp.items():
            ans[k].extend(v)
        return ans
