class Solution {
public:
    int tribonacci(int n) {
        if (n < 2)
            return n;

        vector<int> tribo{0, 1, 1};

        for (int i = 3; i <= n; ++i) {
            const int next = tribo[0] + tribo[1] + tribo[2];
            tribo[0] = tribo[1];
            tribo[1] = tribo[2];
            tribo[2] = next;
        }

        return tribo[2];
    }
};
