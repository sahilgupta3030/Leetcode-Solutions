class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size(), i = 0;
        stack<char> st;

        while (i < n) {
            // if stack is empty or the top element !=  to current char
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                // if top of stack is equal to current char, pop it
                st.pop();
            }
            i++;
        }

        string ans = "";
        while (!st.empty()) {
            char element = st.top();
            st.pop();
            ans += element;
        }

        // Reverse the answer string to as Stack stores in other order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};