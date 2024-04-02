class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> sIndexMap(128, 0); 
    vector<int> tIndexMap(128, 0); 

    for (int i = 0; i < s.length(); ++i) {
      if (sIndexMap[s[i]] != tIndexMap[t[i]])
        return false;
        
      sIndexMap[s[i]] = i + 1;
      tIndexMap[t[i]] = i + 1;
    }

    return true;
  }
};
