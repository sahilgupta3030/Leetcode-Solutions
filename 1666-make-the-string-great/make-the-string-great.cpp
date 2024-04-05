class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        string st(s);
        int i = 0;

        while (i < n) {
            i++;
            if (((st[i] - 'A') == (st[i - 1] - 'a')) ||
                ((st[i] - 'a') == (st[i - 1] - 'A'))) {

                st.erase(i - 1, 2);

                // for rechecking string after removal..
                n = st.length();
                if (n > 1)
                    i = 0;
            }
        }
        return st;
    }
};


