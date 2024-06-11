class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;

        map<int, int> mp;
        for (auto x : arr1)
            mp[x]++;
        // Process elements in order of arr2
        for (auto temp : arr2) {
            if (mp.find(temp) != mp.end()) {
                auto x = mp.find(temp);
                int count = x->second;

                // Create a vector with 'count' occurrences of 'temp'
                vector<int> v(count, temp);
                // Append to the result
                ans.insert(ans.end(), v.begin(), v.end());
                // Remove the element from the map
                mp.erase(temp);
            }
        }

        // Append remaining elements not in arr2, in ascending order
        for (auto x : mp) {
            int ele = x.first;
            int count = x.second;
            vector<int> v(count, ele);
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};