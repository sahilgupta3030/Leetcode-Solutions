class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> sum(m, 0), minLeft(m, 0), minRight(m, 0);
        for (int j = 0; j < m; j++) {
            sum[j] = grid[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    minLeft[j] = sum[j];
                } else {
                    minLeft[j] = min(sum[j], minLeft[j-1]);
                }
            }
            for (int j = m - 1; j >= 0; j--) {
                if (j == m - 1) {
                    minRight[j] = sum[j];
                } else {
                    minRight[j] = min(sum[j], minRight[j+1]);
                }
            }
            for (int j = 0; j < m; j++) {
                sum[j] = INT_MAX;
                if (j-1 >= 0) sum[j] = min(sum[j], minLeft[j-1] + grid[i][j]);
                if (j+1 < m) sum[j] = min(sum[j], minRight[j+1] + grid[i][j]);
            }
        }
        int ans = INT_MAX;
        for (auto val : sum) {
            ans = min(ans, val);
        }
        return ans;
    }
};