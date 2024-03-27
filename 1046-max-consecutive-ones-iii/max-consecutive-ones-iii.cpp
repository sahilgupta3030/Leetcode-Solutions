// SLIDING WINDOW
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0; // left pointer
        int j = 0; // right pointer

        int countZero = 0; // count of zeros in current window
        int ans = 0; // answer

        while (j < n) {
            if (nums[j] == 0) {
                countZero++; // increment zero count if encountered
            }

            while (countZero > k) { // adjust window
                if (nums[i] == 0) {
                    countZero--; // decrement zero count
                }
                i++; // move left pointer
            }
            ans = max(ans, j - i + 1); // update answer
            j++; // move right pointer
        }
        return ans; // return result
    }
};
