class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int size = grid.size(); // row size
        int col_size = grid[0].size(); // col size

        int row = size - 1; 
        int col = 0; 
        int count = 0; 

        while (row >= 0 && col < col_size) {
            if (grid[row][col] < 0) {
                // Add the count of remaining elements in this column
                count += col_size - col;
                row--;
            } else {
                col++;
            }
        }
        return count;
    }
};
