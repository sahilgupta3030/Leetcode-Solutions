class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    // If the input vector is empty, there's no common prefix
    if (strs.empty())
      return "";

    // Loop through characters in the first string
    for (int i = 0; i < strs[0].length(); ++i) {
      // Loop through other strings in vector
      for (int j = 1; j < strs.size(); ++j) {
        // If end of string or different char, return common prefix
        if (i == strs[j].length() || strs[j][i] != strs[0][i])
          return strs[0].substr(0, i);
      }
    }

    // If no prefix found, return the first string
    return strs[0];
  }
};
