class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;            // Count of misplaced heights
        int currentHeight = 1;  // Expected height starting from 1
        vector<int> count(101); // Frequency array for heights 1-100

        // Count each height's occurrences
        for (int height : heights)
            ++count[height];

        // Check heights against expected sorted order
        for (int height : heights) {
            // Find the next expected height
            while (count[currentHeight] == 0)
                ++currentHeight;
            // If height is not in the correct position, increment ans
            if (height != currentHeight)
                ++ans;
            // Decrease count for the used height
            --count[currentHeight];
        }

        return ans;
    }
};
