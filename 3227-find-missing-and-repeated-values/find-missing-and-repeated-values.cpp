class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        const int nSquare = n * n;
        vector<int> count(nSquare + 1);

        for (const vector<int>& row : grid) {
            for (const int num : row) {
                count[num]++;
            }
        }

        int repeated = -1;
        int missing = -1;

        for (int n = 0; n < (nSquare + 1); n++) {
            if (count[n] == 2) {
                repeated = n;
            }
            if (count[n] == 0) {
                missing = n;
            }
        }

        return {repeated, missing};
    }
};