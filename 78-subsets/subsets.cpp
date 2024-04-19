class Solution {
public:
    // Generates all subsets of a given set of numbers
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resultList;
        vector<int> tempSet;

        // Backtrack to generate subsets
        backtrack(resultList, tempSet, nums, 0);

        return resultList;
    }

private:
    // Recursive function to generate subsets
    void backtrack(vector<vector<int>>& resultSets, vector<int>& tempSet,
                   vector<int>& nums, int start) {
        // Add current subset to result
        resultSets.push_back(tempSet);

        // Generate subsets starting from 'start' index
        for (int i = start; i < nums.size(); i++) {
            tempSet.push_back(nums[i]);
            backtrack(resultSets, tempSet, nums, i + 1);
            tempSet.pop_back();
        }
    }
};
