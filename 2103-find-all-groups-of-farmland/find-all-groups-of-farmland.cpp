class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for (int i = 0; i < land.size(); ++i)
            for (int j = 0; j < land[0].size(); ++j)
                if (land[i][j] == 1) {
                    int x = i;
                    int y = j;

                    // Explore the farmland using DFS
                    dfs(land, i, j, x, y);

                    // Add the coordinates of the farmland to the result
                    ans.push_back({i, j, x, y});
                }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& land, int i, int j, int& x, int& y) {
        // Base cases
        if (i < 0 || i == land.size() || j < 0 || j == land[0].size())
            return; // Out of bounds
        if (land[i][j] != 1)
            return; // Not part of farmland

        land[i][j] = 2; // Mark current cell as visited

        // Update the boundaries of the farmland
        x = max(x, i);
        y = max(y, j);

        // Explore adjacent cells
        dfs(land, i + 1, j, x, y); // Down
        dfs(land, i, j + 1, x, y); // Right
    }
};