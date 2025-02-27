class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end());
        int n = arr.size();
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = arr[i], b = arr[j];
                int length = 2;

                while (numSet.count(a + b)) {
                    int temp = a + b;
                    a = b;
                    b = temp;
                    ++length;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength > 2 ? maxLength : 0;
    }
};
