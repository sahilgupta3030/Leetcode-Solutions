class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk; // Stack to track elements in nums2
        unordered_map<int, int> map1; // Map to store next greater element 

        // Traverse nums2 to find next greater element 
        for (int& v : nums2) {
            // if curr element is greater than top of stack
            while (!stk.empty() && stk.top() < v) { 
                map1[stk.top()] = v; // Store next greater element in map1
                stk.pop(); // Pop element from stack
            }
            stk.push(v); // Push current element to stack
        }
        
        vector<int> ans;
        // Traverse nums1 and find next greater element using map1
        // Push next greater element or -1 if not found
        for (int& v : nums1)
            ans.push_back(map1.count(v) ? map1[v] : -1); 
        
        return ans;
    }
};
