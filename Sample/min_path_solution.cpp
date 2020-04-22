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
        int start = grid[0][0];
        int row_size = grid.size();
        int col_size = grid[0].size();
        int goal = grid[col_size-1][row_size-1];
        int sum_val = 0;
        
        vector<int> motion{1, 1};
        vector<vector<int>> sum = grid;
        
        if (row_size > 0 && col_size > 0)
        {
            for (int cb_col = col_size - 1; cb_col >= 0; cb_col--)
            {
                for (int cb_row = row_size  - 1; cb_row >= 0; cb_row--)
                {                
                    if (cb_row + 1 >= row_size && cb_col + 1 < col_size)
                    {
                        sum[cb_col][cb_row] = sum[cb_col][cb_row] + sum[cb_col + 1][cb_row];
                    }
                    else if (cb_row + 1 < row_size && cb_col + 1 >= col_size)
                    {
                        sum[cb_col][cb_row] = sum[cb_col][cb_row] + sum[cb_col][cb_row + 1];
                    }
                    else if (cb_row + 1 == row_size && cb_col + 1 == col_size) {}
                    else
                    {
                         sum[cb_col][cb_row] = sum[cb_col][cb_row] + sum[cb_col][cb_row+1] + sum[cb_col+1][cb_row];
                    }
                    // cout << sum[cb_col][cb_row] << " ";
                }
                // cout << endl;
            }

            int r, c = 0;
            while (grid[r][c] != goal)
            {
                if (r < row_size - motion[0] && c < col_size - motion[1])
                {
                    if (sum[r + motion[0]][c] > sum[r][c + motion[1]])
                    {
                        sum_val = sum_val + grid[r][c + motion[1]];
                        c = c + motion[1];
                    }
                    else
                    {
                        sum_val = sum_val + grid[r + motion[0]][c];
                        r = r + motion[0];
                    }
                }
                else if (r == row_size - motion[0] && c < col_size - motion[1])
                {
                    sum_val = sum_val + grid[r][c + motion[1]];
                    c = c + motion[1];
                }
                else
                {
                    sum_val = sum_val + grid[r + motion[0]][c];
                    r = r + motion[0];
                }
            }
        }
        else
        {
            if (row_size == 0)
            {
                for (int count = 0; count < grid[0].size(); count++)
                {
                    sum_val = sum_val + grid[0][count];
                }
            }
            else
            {
                for (int count = 0; count < grid.size(); count++)
                {
                    sum_val = sum_val + grid[count][0];
                }
            }
        }
        
        return sum_val;
    }
};