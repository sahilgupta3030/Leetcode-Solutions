// for dp
vector<int> dp(101, -1);

class Solution {
public:
    int n = 0;
    int numDecodingsHelper(string s, int pos) {
        // base case
        if (pos == n)
            return 1;
        if (s[pos] == '0')
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        // taking 1num at a time
        int count = numDecodingsHelper(s, pos + 1);
        // taking 2num at a time
        if (pos < n - 1 && s.substr(pos, 2) < "27") {
            count += numDecodingsHelper(s, pos + 2);
        }
        return dp[pos] = count;
    }

    // main function..
    int numDecodings(string s) {
        n = s.size();

        fill(dp.begin(), dp.end(), -1);
        return numDecodingsHelper(s, 0);
    }
};