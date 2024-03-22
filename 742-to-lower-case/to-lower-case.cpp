class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};

// Lowercase: 97-122 (a-z)
// Uppercase: 65-90 (A-Z)



