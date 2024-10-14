# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        k -= 1

        ans: list[int] = []

        def sol(root: TreeNode | None) -> tuple[int, int, bool]:
            if not root:
                return 0, 0, True
            
            ansl, ld, ls = sol(root.left)
            ansr, rd, rs = sol(root.right)

            # is perfect

            curr = False
            if ls and rs and abs(ld - rd) == 0:
                ans.append(ansl+ ansr + 1)
                curr = True


            return ansl + ansr + 1 ,max(ld, rd) + 1, curr
        
        sol(root = root)
        ans.sort(reverse=True)
        print(ans)
        return ans[k] if len(ans) > k else -1