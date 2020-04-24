/*
    MINIMUM PATH SOLUTION
    
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
    which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example:

    Input:
    [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    Output: 7
    Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        
        if (row_size == 0 && col_size == 0) {return 0;}

        for (int col = 0; col < col_size; col++)
        {
            for (int row = 0; row < row_size; row++)
            {                
                if (row > 0 && col > 0)
                {
                    grid[row][col] += min(grid[row-1][col], grid[row][col-1]);
                }
                else if (row > 0)
                {
                    grid[row][col] += grid[row-1][col];
                }
                else if (col > 0)
                {
                    grid[row][col] += grid[row][col-1];
                }
            }
        }
        
        return grid[row_size-1][col_size-1];
    }
};
