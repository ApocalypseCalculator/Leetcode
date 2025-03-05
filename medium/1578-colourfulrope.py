# 1578. Minimum Time to Make Rope Colorful

# strat: just track segments and its max val

class Solution(object):
    def minCost(self, colors, neededTime):
        curcost = 0
        segmentcost = 0
        segmentmax = 0
        cursegment = '_'
        for i, c in enumerate(colors):
            if c != cursegment: 
                curcost = curcost + segmentcost - segmentmax
                # start new segment
                cursegment = c
                segmentcost = 0
                segmentmax = 0
            segmentcost+=neededTime[i]
            if neededTime[i] > segmentmax:
                segmentmax = neededTime[i]
        
        curcost = curcost + segmentcost - segmentmax
        return curcost