class Solution {
public:
    int maximumSum(vector<int>& numbers) {
        vector<vector<int>> digitSumGroups(100);
      
        for (int& number : numbers) {
            int digitSum = 0;
            for (int value = number; value > 0; value /= 10) {
                digitSum += value % 10;
            }
            digitSumGroups[digitSum].emplace_back(number);
        }
      
        int maxPairSum = -1;
        for (auto& group : digitSumGroups) {
            if (group.size() > 1) {
                sort(group.rbegin(), group.rend());
                maxPairSum = max(maxPairSum, group[0] + group[1]);
            }
        }
        return maxPairSum;
    }
};
