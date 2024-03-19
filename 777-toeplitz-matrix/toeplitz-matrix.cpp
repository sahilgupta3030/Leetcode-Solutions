class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
         int m = matrix.size();
        int n = matrix[0].size();
        
        // Iterate through each element of the matrix except for the first row and first column
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // Check if the current element matches the one directly above and to the left of it
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false; // If not, return false
                }
            }
        }
        return true;
        
    }
};