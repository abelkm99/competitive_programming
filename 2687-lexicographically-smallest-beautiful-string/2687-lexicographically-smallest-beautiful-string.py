class Solution:
    def smallestBeautifulString(self, s: str, k: int) -> str:
        arr = [ord(c) - ord('a') for c in s]
        n = len(s)

        i = n - 1

        def valid(i):
            return i >= 1 and arr[i] == arr[i - 1] or i >= 2 and arr[i] == arr[i -2]
        # print(arr)
        while i >= 0:
            arr[i] += 1
            while valid(i):
                arr[i] += 1
                if arr[i] == k:
                    break
            if arr[i] == k:
                arr[i] = 0
                i -= 1
                continue
            else:
                break 

        # print(arr)

        for j in range(i, n):
            while valid(j):
                arr[j] += 1
                arr[j] %= k

        ans =  "".join([chr(x + ord('a')) for x in arr])
        # print(ans)
        return ans if ans > s else ""