class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        unordered_map<int, int> map1; // Renamed from count

        for (const int num : nums1)
            ++map1[num];

        for (const int num : nums2) {
            auto iterator = map1.find(num);
            // iterator != map1.end() // means num not found
            if (iterator != map1.end() && iterator->second > 0) {
                ans.push_back(num);
                iterator->second--; // decrease the count of num in the map
            }
        }

        return ans;
    }
};
