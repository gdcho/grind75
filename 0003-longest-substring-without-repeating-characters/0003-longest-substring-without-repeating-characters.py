class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        p = 0
        d = {}
        for i, c in enumerate(s):
            if c not in d or d[c] < p:
                ans = max(ans, i - p + 1)
            else:
                p = d[c] + 1
            d[c] = i
        return ans