class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        return binary_search(0, x, x);
    }

private:
    int binary_search(int left, int right, int target) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == target / mid) {
                return mid;
            } else if (mid < target / mid) {
                return binary_search(mid + 1, right, target);
            } else {
                return binary_search(left, mid - 1, target);
            }
        } else {
            return right;
        }
    }
};
