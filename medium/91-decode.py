# 91. Decode Ways

# strat: DP by substring

class Solution(object):
    def numDecodings(self, s):
        memo = {}
        def findWays(idx): 
            if idx in memo:
                return memo[idx]
            if idx >= len(s):
                return 1
            if s[idx:][:1] == "0":
                return 0
            if idx == len(s)-1:
                return 1
            double = int(s[idx:][:2])
            ways = 0
            if double <= 26: 
                ways = findWays(idx+1) + findWays(idx+2)
            else: 
                ways = findWays(idx+1)
            memo[idx] = ways
            return ways
        return findWays(0)