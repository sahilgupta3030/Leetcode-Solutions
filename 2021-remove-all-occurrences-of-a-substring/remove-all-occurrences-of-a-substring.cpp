class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = part.size();

        for (char c : s) {
            st.push(c);

            // Check if top characters match 'part'
            if (st.size() >= m) {
                string temp = "";
                for (int i = 0; i < m; ++i) {
                    temp = st.top() + temp;
                    st.pop();
                }

                // If not equal to 'part', push characters back
                if (temp != part) {
                    for (char ch : temp) {
                        st.push(ch);
                    }
                }
            }
        }

        // Construct result string from stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};





// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         int m = part.size();
//         while (s.find(part) != -1) {
//             s = s.erase(s.find(part), m);
//         }
//         return s;
//     }
// };