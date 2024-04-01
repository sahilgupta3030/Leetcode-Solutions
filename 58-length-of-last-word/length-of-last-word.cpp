class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.size();
        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            // Skip trailing spaces
            if (s[i] == ' ' && count == 0)
                continue;

            // Break loop when word ends
            if (s[i] == ' ')
                break;

            count++;
        }
        return count;
    }
};
