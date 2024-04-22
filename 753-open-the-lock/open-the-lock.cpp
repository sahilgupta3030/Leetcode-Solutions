class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Create a set of deadend combinations for quick lookup
        unordered_set<string> dead(deadends.begin(), deadends.end());
        // Set to track visited combinations to avoid repetition
        unordered_set<string> visited;
        
        // Initialize a queue with starting combination
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int level = 0; // Track the level of BFS traversal
        
        // BFS traversal
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                // Retrieve the current combination from the queue
                string current = q.front();
                q.pop();
                // Check if the current combination matches the target
                if(current == target) return level;
                // Skip if the combination is a deadend
                if(dead.count(current)) continue;
                // Generate next possible combinations by changing each digit
                for (int j = 0; j < 4; ++j) {
                    string up = current;
                    string down = current;
                    
                    // Rotate the digit up and down
                    up[j] = (up[j] - '0' + 1) % 10 + '0';
                    down[j] = (down[j] - '0' + 9) % 10 + '0';
                    
                    // Add new combinations to the queue if not visited before
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
            level++; // Increment level for the next depth of traversal
        }
        // If the target combination cannot be reached
        return -1;
    }
};
