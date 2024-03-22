class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0, n = s.size() / 2;
       
        for (int i = 0; i < n; ++i) {
            count += vowels.count(s[i]);
            count -= vowels.count(s[i + n]);
        }
        return count == 0;
    }
};
