// Approach-2 (1 Pass - Use equation)
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;

        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            result = max(result, zeros - ones);
        }
        if (s[n - 1] == '1') {
            ones++;
        }
        return result + ones;
    }
};

// // Approach-1 (Making use of ones count - 2 Passes)
// class Solution {
// public:
//     int maxScore(string s) {
//         int n = s.length();
//         int result = INT_MIN;

//         int total_ones = count(s.begin(), s.end(), '1');
//         int zeros = 0;
//         int ones = 0;

//         for (int i = 0; i <= (n - 2); i++) {
//             if (s[i] == '1') {
//                 ones++;
//             } else {
//                 zeros++;
//             }
//             int right_ones = total_ones - ones;
//             result = max(result, zeros + right_ones);
//         }
//         return result;
//     }
// };