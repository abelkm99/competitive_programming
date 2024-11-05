class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        cnt: dict[str, int] = defaultdict(int)
        longest = 0
        for r, c in enumerate(s):
            while(cnt[c]):
                cnt[s[l]] -= 1
                l += 1
            cnt[c] += 1
            longest = max(longest, r - l + 1)
        return longest