class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> curr;
        backtrack(res, nums, curr, visited);
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums,
                   vector<int>& curr, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i])
                continue;
            curr.push_back(nums[i]);
            visited[i] = true;
            backtrack(res, nums, curr, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
};
