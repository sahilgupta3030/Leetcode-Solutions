class Solution {
public:
    int longestIdealString(string s, int k) {

        // Initialize a vector dp of size 26 with 0s
        vector<int> dp(26, 0);
        int ans = 1;

        // Iterate through the characters of string s
        for (int i = 0; i < s.size(); i++) {

            // Calculate the range of characters to consider
            int x = max(0, s[i] - 'a' - k);
            int y = min(25, s[i] - 'a' + k);

            int temp = 1;

            // Iterate through the range of characters
            for (int j = x; j <= y; j++) {
                // Update temp with the maximum of its current value and 1 plus
                // dp[j]
                temp = max(temp, 1 + dp[j]);
            }
            // Update dp[s[i]-'a'] with temp
            dp[s[i] - 'a'] = temp;
            // Update ans with the maximum of its current value and temp
            ans = max(ans, temp);
        }
        return ans;
    }
};
