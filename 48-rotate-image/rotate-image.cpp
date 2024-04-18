class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();

        // find transpose
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // flip horizontally - For clock wise rotation
        // or reverse
        for (int i = 0; i < N; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};