class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')' && !st.empty())
                st.pop();
            else if (s[i] == ')')
                s[i] = '@'; // problematic bracket index stored
        }

        while (!st.empty()) {
            s[st.top()] = '@'; // deleting
            st.pop();
        }

        // remove @ from string
        s.erase(remove(s.begin(), s.end(), '@'), s.end());
        return s;
    }
};