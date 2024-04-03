class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    vector<int> count(26);

    for (const char ch : s)
      ++count[ch - 'a'];

    for (const char ch : t) {
      if (count[ch - 'a'] == 0)
        return false;
      --count[ch - 'a'];
    }

    return true;
  }
};
