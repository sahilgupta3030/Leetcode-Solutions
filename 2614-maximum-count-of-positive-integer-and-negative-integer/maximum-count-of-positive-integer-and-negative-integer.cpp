class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int size=nums.size();
        int cntpositive = 0, cntnegative = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] > 0)
                cntpositive++;
            else if (nums[i] < 0)
                cntnegative++;
        }

        return max(cntpositive, cntnegative);
    }
};