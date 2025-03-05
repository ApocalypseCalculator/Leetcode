# 44. Wildcard Matching

# strat: DP by substring of both input and the pattern
# could be a lot faster

class Solution(object):
    def isMatch(self, s, p):
        memo = {}
        def matchSub(sidx, pidx): 
            if sidx in memo and pidx in memo[sidx]:
                return memo[sidx][pidx]
            if sidx not in memo:
                memo[sidx] = {}
            if sidx == len(s) and pidx == len(p):
                return True
            if sidx > len(s) or pidx >= len(p): 
                return False
            result = False
            if (sidx < len(s) and s[sidx] == p[pidx]) or p[pidx] == '?': 
                result = matchSub(sidx+1, pidx+1)
            elif p[pidx] == '*':
                result = matchSub(sidx+1, pidx) or matchSub(sidx, pidx+1) or matchSub(sidx+1, pidx+1)
            memo[sidx][pidx] = result
            return result
        return matchSub(0,0)