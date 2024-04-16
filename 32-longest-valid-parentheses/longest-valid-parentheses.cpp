class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int max_length = 0;
        stk.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_length = max(max_length, i - stk.top());
                }
            }
        }
        return max_length;
    }
};