# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        memo = {}
        for g_id, x in enumerate(lists):
            if x:
                memo[g_id] = x
                heappush(heap, (x.val, g_id))

        ans = ListNode()
        curr = ans
        while heap:
            v, g_id = heappop(heap)

            curr.next = ListNode(v)
            curr = curr.next
            node = memo[g_id]
            if node.next:
                memo[g_id] = node.next
                heappush(heap,(node.next.val, g_id))
        
        return ans.next