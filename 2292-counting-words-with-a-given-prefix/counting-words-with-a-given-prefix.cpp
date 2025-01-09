class Solution {
public:
    int prefixCount(vector<string>& words, const string& pref) {
        int count = 0;
        for (const auto& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};