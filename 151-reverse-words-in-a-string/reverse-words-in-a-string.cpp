// Approach-1 (Perfect use of std::stringstream)
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";
        
        // By default stringstream tokenizes on space character
        while (ss >> token) {
            result = token + " " + result;
        }

        return result.substr(0, result.length() - 1);
    }
};