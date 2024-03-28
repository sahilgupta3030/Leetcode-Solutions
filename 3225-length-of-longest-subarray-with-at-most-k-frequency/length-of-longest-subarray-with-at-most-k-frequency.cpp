class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {

    int i=0;
    int j=0;
    int n=nums.size();
    int ans = 0;
    unordered_map<int, int> count;

    while (j < n) {
      count[nums[j]]++;

      while (count[nums[j]] == k + 1)
        count[nums[i++]]--;

      ans = max(ans, j - i + 1);
      j++;
    }
    return ans;
  }
};