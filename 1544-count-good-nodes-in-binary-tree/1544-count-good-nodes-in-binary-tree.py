# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode, p: int = -1000000000) -> int:
        if not root:
            return 0
        return int(root.val >= p) + self.goodNodes(root.left, max(root.val, p)) + self.goodNodes(root.right, max(root.val, p))
