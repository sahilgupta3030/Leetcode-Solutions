class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string current = q.front();
                q.pop();
                if(current == target) return level;
                if(dead.count(current)) continue;
                for (int j = 0; j < 4; ++j) {
                    string up = current;
                    string down = current;
                    
                    up[j] = (up[j] - '0' + 1) % 10 + '0';
                    down[j] = (down[j] - '0' + 9) % 10 + '0';
                    
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }   
            }
            level++;
        }
        return -1;
    }
};