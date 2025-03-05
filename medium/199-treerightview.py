# 199. Binary Tree Right Side View

# strat: traverse tree and append nodes left to right. then the rightmost is always last in the list 
# (note: the list is unnecessary lol just track 1 element)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        views = []
        def traverse(current, layer): 
            if current is None: 
                return
            if layer == len(views):
                views.append([])
            views[layer].append(current.val)
            traverse(current.left, layer+1)
            traverse(current.right, layer+1)
        traverse(root, 0)
        def getlast(arr): 
            return arr[-1]
        return map(getlast, views)