class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        vector<int> count(128);

        // Sliding window: left and right pointers
        // Increase count of char at index right
        for (int left = 0, right = 0; right < s.length(); ++right) {
            ++count[s[right]];
            // If count of char at index right is greater than 1
            // Decrease count of char at index left and move left to right
            while (count[s[right]] > 1)
                --count[s[left++]];

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
