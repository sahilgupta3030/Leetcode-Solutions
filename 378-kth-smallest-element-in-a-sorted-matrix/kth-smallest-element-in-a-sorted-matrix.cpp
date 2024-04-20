struct T {
  int i; // Row
  int j; // Column
  int num; // Value
  T(int i, int j, int num) : i(i), j(j), num(num) {}
};

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto compare = [&](const T& a, const T& b) { return a.num > b.num; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

    // Add first element of each row to min heap
    for (int i = 0; i < k && i < matrix.size(); ++i)
      minHeap.emplace(i, 0, matrix[i][0]);

    // Pop elements until kth smallest is found
    while (k-- > 1) {
      const auto [i, j, _] = minHeap.top();
      minHeap.pop();
      if (j + 1 < matrix[0].size())
        minHeap.emplace(i, j + 1, matrix[i][j + 1]); // Move to next column
    }

    return minHeap.top().num; // Return kth smallest
  }
};
