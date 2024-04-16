class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        int n = nums1.size();
        vector<int> res(n);
        stack<int> st;

        // Traverse nums2
        for (int i = 0; i < nums2.size(); i++) {
            // Find next greater element for current element in nums2
            while (st.size() && st.top() < nums2[i]) {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        // Populate result vector with next greater elements
        for (int i = 0; i < n; i++) {
            if (mp[nums1[i]] == 0) {
                res[i] = -1; // No next greater element found
            } else {
                res[i] = mp[nums1[i]]; // Set the next greater element found
            }
        }
        return res;
    }
};
