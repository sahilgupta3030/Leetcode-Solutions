class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> combinations{""};
        const vector<string> digitToLetters{
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // Iterate over digits
        for (const char digit : digits) {
            vector<string>
                tempCombinations; // Temporary vector for new combinations
            // Iterate over existing combinations
            for (const string& combination : combinations)
                // Iterate over letters for current digit
                for (const char letter : digitToLetters[digit - '0'])
                    tempCombinations.push_back(
                        combination +
                        letter); // Append letter to each combination
            combinations = move(tempCombinations); // Update combinations
        }

        return combinations;
    }
};
