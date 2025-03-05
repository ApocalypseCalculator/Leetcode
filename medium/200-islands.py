# 200. Number of Islands

# SLOW SOLUTION

class Solution(object):
    def numIslands(self, grid):
        nodes = {}

        # O(m*n) operation
        for rowidx, row in enumerate(grid): 
            for colidx, col in enumerate(row): 
                if col == "1": 
                    nodes[(rowidx, colidx)] = {
                        'visited': False,
                        'adjacents': []
                    }
                    # scan for adjacents here
                    if rowidx > 0 and grid[rowidx-1][colidx] == "1": 
                        nodes[(rowidx, colidx)]['adjacents'].append((rowidx-1, colidx))
                    if rowidx < len(grid)-1 and grid[rowidx+1][colidx] == "1": 
                        nodes[(rowidx, colidx)]['adjacents'].append((rowidx+1, colidx))
                    if colidx > 0 and grid[rowidx][colidx-1] == "1": 
                        nodes[(rowidx, colidx)]['adjacents'].append((rowidx, colidx-1))
                    if colidx < len(row)-1 and grid[rowidx][colidx+1] == "1": 
                        nodes[(rowidx, colidx)]['adjacents'].append((rowidx, colidx+1))
                    
        # now we search
        def propogate(key): 
            if nodes[key]['visited']: 
                return
            else: 
                nodes[key]['visited'] = True
                for neighbour in nodes[key]['adjacents']:
                    propogate(neighbour)
        islands = 0
        while True:
            first_match = next((key for key, value in nodes.items() if not value['visited']), None)
            if first_match is None:
                break
            else: 
                islands = islands + 1
                propogate(first_match)

        return islands
