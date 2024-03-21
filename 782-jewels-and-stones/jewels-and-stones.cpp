class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet;

        // Populate the set with jewels
        for (int i = 0; i < jewels.size(); i++) {
            jewelSet.insert(jewels[i]);
        }

        int score = 0;
        // Count jewels in stones
        for (int i = 0; i < stones.size(); i++) {
            if (jewelSet.find(stones[i]) != jewelSet.end()) {
                score++;
            }
        }

        return score;
    }
};
