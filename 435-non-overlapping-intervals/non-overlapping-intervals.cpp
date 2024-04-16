class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;            // Count of num of intervals to be removed
        int n = intervals.size(); // No of intervals
        int left = 0;             // left interval
        int right = 1;            // right interval

        // unless all intervals are compared
        while (right < n) {
            // Non-overlapping case
            if (intervals[left][1] <= intervals[right][0]) {
                left = right;
                right += 1;

            } // Overlapping case-1 (Remove right interval)
            else if (intervals[left][1] <= intervals[right][1]) {
                count += 1; // delete right
                right += 1;
            } // Overlapping case-2 (Remove left interval)
            else if (intervals[left][1] > intervals[right][1]) {
                count += 1;
                left = right;
                right += 1;
            }
        }

        return count;
    }
};