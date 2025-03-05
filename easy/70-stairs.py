# 70. Climbing Stairs

# strat: DP

class Solution(object):
    def climbStairs(self, n):
        memo = {}

        def countStairs(m): 
            if m <= 1:
                return 1
            if m in memo: 
                return memo[m]
            needed = countStairs(m-1) + countStairs(m-2)
            memo[m] = needed
            return needed
        
        return countStairs(n)