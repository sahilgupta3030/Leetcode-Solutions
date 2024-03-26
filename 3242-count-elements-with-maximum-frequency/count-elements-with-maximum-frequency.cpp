
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        int maxFrequency = 0;

        // Count the frequency of each element
        for (int num : nums) {
            frequencyMap[num]++;
            maxFrequency = max(maxFrequency, frequencyMap[num]);
        }

        // Count the number of elements with maximum frequency
        int count = 0;
        for (const auto& pair : frequencyMap) {
            if (pair.second == maxFrequency) {
                count += pair.second; // Add the frequency of elements with maximum frequency
            }
        }

        return count;
    }
};