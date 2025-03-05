# 42. Trapping Rain Water

# strat: two pointer track left right max

class Solution(object):
    def trap(self, height):
        left = 1
        right = len(height) - 2
        lmax = height[left - 1]
        rmax = height[right + 1]
        res = 0
        while left <= right:
            if rmax <= lmax:
                res += max(0, rmax - height[right])
                rmax = max(rmax, height[right])
                right -= 1
            else: 
                res += max(0, lmax - height[left])
                lmax = max(lmax, height[left])
                left += 1
        return res