# 10. Regular Expression Matching

# strat: DP by substring of both input and the pattern
# space could be improved by not using a dict for memoization

class Solution(object):
    def isMatch(self, s, p):
        memo = {}
        def matchSub(sidx, pidx): 
            if sidx in memo and pidx in memo[sidx]:
                return memo[sidx][pidx]
            if sidx not in memo:
                memo[sidx] = {}
            
            if sidx == len(s) and pidx == len(p): # reached end of both strings
                return True
            if sidx > len(s) or pidx >= len(p): 
                return False

            result = False
            if (sidx < len(s) and s[sidx] == p[pidx]) or p[pidx] == '.': 
                if pidx < len(p)-1 and p[pidx+1] == '*':
                    result = matchSub(sidx+1, pidx) or matchSub(sidx+1, pidx+2) or matchSub(sidx, pidx+2)
                else: 
                    result = matchSub(sidx+1, pidx+1)
            elif pidx < len(p)-1 and p[pidx+1] == '*':
                result = matchSub(sidx, pidx+2)
            memo[sidx][pidx] = result
            return result
        
        return matchSub(0,0)