class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        int n = word.length();

        for (int i = 0; i < n; ++i) {
            unordered_set<char> found;
            for (int j = i; j < n; ++j) {
                if (vowels.find(word[j]) != vowels.end()) {
                    found.insert(word[j]);
                    if (found.size() == 5) {
                        ++count;
                    }
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
