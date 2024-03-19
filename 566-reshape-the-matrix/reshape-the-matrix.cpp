class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(); // Get number of rows in original matrix
        int m = mat[0].size(); // Get number of columns in original matrix

        if (n * m != r * c) // Check if reshape is possible
            return mat; // Return original matrix if reshape is not possible

        int row = 0; // Initialize row index
        int col = 0; // Initialize column index
        // Create the reshaped matrix
        vector<vector<int>> ans(r, vector<int>(c)); 

        for (int i = 0; i < r; i++) { 
            for (int j = 0; j < c; j++) { 
                if (col == m) { 
                    // If end of column in original matrix is reached
                    row++; // Move to the next row in original matrix
                    col = 0; // Reset column index
                }
                // Fill reshaped matrix with elements from original matrix
                // Move to the next column in original matrix
                ans[i][j] = mat[row][col]; 
                col++; 
            }
        }
        return ans;
    }
};
