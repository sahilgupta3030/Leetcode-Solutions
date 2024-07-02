class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        unordered_map<int, int> map1;

        for (const int num : nums1)
            ++map1[num];

        for (const int num : nums2) {
            auto iterator = map1.find(num);
            if (iterator != map1.end() && iterator->second > 0) {
                ans.push_back(num);
                iterator->second--; 
            }
        }

        return ans;
    }
};
