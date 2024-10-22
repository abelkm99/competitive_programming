from collections import deque
from heapq import heapify, heappush, heappop
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        heap = []

        dq = deque()

        dq.append(root)

        while dq:
            l_childs: int = len(dq)
            sm: int = 0
            for _ in range(l_childs):
                
                node = dq.popleft()
                if not node:
                    continue

                sm += node.val
                dq.append(node.left)
                dq.append(node.right)
                    
            if sm:
                heappush(heap, sm)
            # print("sm", sm, heap)
            while len(heap) > k:
                heappop(heap)

        print(heap)

        return heap[0] if len(heap) == k else -1