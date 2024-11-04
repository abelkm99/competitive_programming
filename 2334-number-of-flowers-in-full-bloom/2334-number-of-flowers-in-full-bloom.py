class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        # how many valid answers do i have inside my heap 
        # it's not even about the length
        heap = []
        p = 0
        flowers.sort()
        memo = {}
        for q in sorted(people):
            if q in memo:
                continue
            while p < len(flowers) and not flowers[p][0] > q:
                # eskehone dires
                heappush(heap, (flowers[p][1], flowers[p][0]))
                p += 1
            # we are sooo sure that all the numbers inside the heap are doesn't start after q
            # so we can assert it holds that q is >= the start of all the element
            # now what we need to check is remove all the values where the flower.end is less than q
            while heap and heap[0][0] < q:
                heappop(heap)
            memo[q] = len(heap)
        ans = [memo[q] for q in people]
        return ans
