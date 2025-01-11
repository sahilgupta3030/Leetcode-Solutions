class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        int letterCount[26] = {0};
        for (char& c : s) {
            ++letterCount[c - 'a'];
        }

        int oddCount = 0;
        for (int count : letterCount) {
            oddCount += count & 1;
        }

        return oddCount <= k;
    }
};