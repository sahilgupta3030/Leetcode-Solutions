// class Solution {
// public:
//     int hammingWeight(int n) {
//         int count = 0;

//         while (n > 0) {
//             count += (n & 1); // add 1 if last bit is set
//             n >>= 1;          // shift right by 1
//         }

//         return count;
//     }
// };

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        string binForm = "";
        while (n > 0) {
            binForm = char((n % 2) + '0') + binForm;
            n /= 2;
        }

        for (char bit : binForm) {
            if (bit == '1') {
                count++;
            }
        }

        return count;
    }
};