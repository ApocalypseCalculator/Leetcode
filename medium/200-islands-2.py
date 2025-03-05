# 200. Number of Islands

# FAST SOLUTION
# strat: recursively mark all adjacents as soon as we encounter a 1, incrementing the island count

class Solution(object):
    def numIslands(self, grid):
        def markIsland(rowidx, colidx): 
            grid[rowidx][colidx] = "0"
            # scan for adjacents here
            if rowidx > 0 and grid[rowidx-1][colidx] == "1": 
                markIsland(rowidx-1, colidx)
            if rowidx < len(grid)-1 and grid[rowidx+1][colidx] == "1": 
                markIsland(rowidx+1, colidx)
            if colidx > 0 and grid[rowidx][colidx-1] == "1": 
                markIsland(rowidx, colidx-1)
            if colidx < len(grid[0])-1 and grid[rowidx][colidx+1] == "1": 
                markIsland(rowidx, colidx+1)

        islands = 0
        for rowidx, row in enumerate(grid): 
            for colidx, col in enumerate(row): 
                if col == "1": 
                    islands = islands+1
                    markIsland(rowidx, colidx)

        return islands
        