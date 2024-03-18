class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; ++i) {
            int minInRow = matrix[i][0]; // Initialize minInRow with the first element of the row
            int colIndex = 0; // Initialize colIndex with 0
            
            // Find the minimum element in the current row
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] < minInRow) {
                    minInRow = matrix[i][j];
                    colIndex = j; // Update colIndex to the column index of the minimum element
                }
            }
            
            // Check if the minimum element in the row is also the maximum in its column
            bool isLucky = true;
            for (int k = 0; k < m; ++k) {
                if (matrix[k][colIndex] > minInRow) {
                    isLucky = false;
                    break;
                }
            }
            
            // If the element is lucky, add it to the list
            if (isLucky) {
                luckyNumbers.push_back(minInRow);
            }
        }
        
        return luckyNumbers;
    }
};