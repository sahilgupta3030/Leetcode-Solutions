class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resultList;
        vector<int> tempSet;

        backtrack(resultList, tempSet, nums, 0);

        return resultList;
    }

private:
    void backtrack(vector<vector<int>>& resultSets, vector<int>& tempSet,
                   vector<int>& nums, int start) {
        resultSets.push_back(tempSet);

        for (int i = start; i < nums.size(); i++) {
            tempSet.push_back(nums[i]);
            backtrack(resultSets, tempSet, nums, i + 1);
            tempSet.pop_back();
        }
    }
};
