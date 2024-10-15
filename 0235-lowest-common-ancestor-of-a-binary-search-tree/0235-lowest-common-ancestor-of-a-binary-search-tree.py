# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans: TreeNode = None
        def solve(root, p, q) -> tuple[bool, bool]:
            nonlocal ans
            if root == None:
                return False, False
                
            l1, r1 = solve(root.left, p, q)
            l2, r2 = solve(root.right, p, q)

            ans_p = l1 or l2 or p == root.val
            ans_q = r1 or r2 or q == root.val

            if ans_p and ans_q and not ans:
                print("store", root.val)
                ans = root

            
            return ans_p, ans_q
        solve(root, p.val, q.val)
        return ans