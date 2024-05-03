class Solution {
public:
    // Function to split version string into tokens
    vector<string> getTokens(string version) {
        stringstream ss(version);
        string token = "";
        vector<string> version_tokens;

        // Splitting version string by '.'
        while (getline(ss, token, '.')) {
            version_tokens.push_back(token);
        }

        return version_tokens;
    }
    
    // Function to compare two version strings
    int compareVersion(string version1, string version2) {

        // Getting tokens for both versions
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int m = v1.size();
        int n = v2.size();

        int i = 0;
        // Comparing corresponding tokens of both versions
        while (i < m || i < n) {

            int a = i < m ? stoi(v1[i]) : 0;
            int b = i < n ? stoi(v2[i]) : 0;

            // Comparing token values
            if (a > b)
                return 1;
            else if (b > a)
                return -1;
            else
                i++; // Move to next token if curr ones are equal

        }
        return 0; 
    }
};
