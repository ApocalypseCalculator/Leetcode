# 1137. N-th Tribonacci Number

# strat: DP
# see C++ solution for even faster one

class Solution(object):
    def tribonacci(self, n):
        memo = {}

        def countStairs(m): 
            if m == 1:
                return 1
            if m == 0:
                return 0
            if m == 2:
                return 1
            if m in memo: 
                return memo[m]
            needed = countStairs(m-1) + countStairs(m-2) + countStairs(m-3)
            memo[m] = needed
            return needed
        
        return countStairs(n)