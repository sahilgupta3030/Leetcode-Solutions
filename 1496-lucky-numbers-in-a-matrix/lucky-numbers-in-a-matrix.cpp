class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> foundLucky;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            int min_row = matrix[i][0];
            int col_index = 0;

            // Find the minimum element in the current row
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < min_row) {
                    min_row = matrix[i][j];
                    col_index = j;
                }
            }

            bool isLucky = true;

            // Check if the minimum element in the row is also the maximum in its column
            for (int k = 0; k < m; k++) { // Iterate over rows, not columns
                if (matrix[k][col_index] > min_row) {
                    isLucky = false;
                    break;
                }
            }

            // If the element is lucky, add it to the list
            if (isLucky) {
                foundLucky.push_back(min_row);
            }
        }

        return foundLucky;
    }
};
