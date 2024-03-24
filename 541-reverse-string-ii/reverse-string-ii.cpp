class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        // Traverse the string with step 2*k
        for (int i = 0; i < n; i += 2 * k) {
            // if fewer than k char left, reverse all remaining char
            if ((n - i) < k) {
                reverse(s.begin() + i, s.end());
            } 
            // if k or more char left, reverse the first k char
            else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};
