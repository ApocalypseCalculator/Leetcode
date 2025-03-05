# 198. House Robber

# strat: DP by subarr (only 2 possibilities at any stage)

class Solution(object):
    def rob(self, nums):
        memo = {}
        def robct(start): 
            if start in memo: 
                return memo[start]
            if start == len(nums)-1 or start == len(nums)-2: 
                return nums[start]
            if start >= len(nums):
                return 0
            maxval = nums[start] + max(robct(start+2), robct(start+3))
            memo[start] = maxval
            return maxval
        return max(robct(0), robct(1))