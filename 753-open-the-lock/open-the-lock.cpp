class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        
        queue<string> q;
        unordered_set<string> visited;
        
        q.push("0000");
        visited.insert("0000");
        
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string cur = q.front(); q.pop();
                if (cur == target) return level;
                if (dead.count(cur)) continue;
                for (int j = 0; j < 4; ++j) {
                    for (int k = -1; k <= 1; k += 2) {
                        string next = cur;
                        next[j] = (next[j] - '0' + k + 10) % 10 + '0';
                        if (!visited.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            ++level;
        }
        return -1;
    }
};
