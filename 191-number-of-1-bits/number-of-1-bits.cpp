class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n > 0) {
            count += (n & 1); // add 1 if last bit is set
            n >>= 1;          // shift right by 1
        }

        return count;
    }
};
