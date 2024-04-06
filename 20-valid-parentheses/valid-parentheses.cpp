class Solution {
public:
    bool isValid(string s) {

        if (s.empty())
            return false;

        stack<char> st;
        for (auto i : s) {
            if (i == '(' or i == '{' or i == '[') {
                st.push(i);
            }

            else {
                if (!st.empty() && ((st.top() == '(' and i == ')') or
                                    (st.top() == '{' and i == '}') or
                                    (st.top() == '[' and i == ']'))) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
