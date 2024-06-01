class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int len = s.length();

        for (int i = 0; i < (len - 1); ++i)
            ans += abs(s[i] - s[i + 1]);

        return ans;
    }
};