class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> count(501, 0);

        for (int num : nums)
            count[num]++;

        for (int c : count) {
            if (c % 2 != 0)
                return false;
        }

        return true;
    }
};
