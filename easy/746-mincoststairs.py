# 746. Min Cost Climbing Stairs

# strat: DP

class Solution(object):
    def minCostClimbingStairs(self, cost):
        memo = {}
        def solve(start): 
            if start >= len(cost): 
                return 0
            if start in memo: 
                return memo[start]
            tc = cost[start] + min(solve(start+1), solve(start+2))
            memo[start] = tc
            return tc
        
        return min(solve(0), solve(1))