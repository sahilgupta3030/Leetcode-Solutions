class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;

        for (auto x : strs) {
            string temp = x;          // Original string
            sort(x.begin(), x.end()); // Sorted string as key
            umap[x].push_back(temp);  // Add to map
        }

        for (auto x : umap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};