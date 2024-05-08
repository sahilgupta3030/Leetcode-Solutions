class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> indices;
        int n = score.size();

        for(int i = 0; i < n; i++) {
            indices.push_back({score[i], i});
        }
        sort(indices.rbegin(), indices.rend());

        vector<string> result(n);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                result[indices[i].second] = "Gold Medal";
            } else if(i == 1) {
                result[indices[i].second] = "Silver Medal";
            } else if(i == 2) {
                result[indices[i].second] = "Bronze Medal";
            } else {
                result[indices[i].second] = to_string(i + 1);
            }
        }
        return result;
    }
};
