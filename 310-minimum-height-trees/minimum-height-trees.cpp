class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0}; // If only one node, it's the root

        vector<vector<int>> adj(n); // Adjacency list
        vector<int> degree(n);      // Degrees of nodes

        // Build adjacency list and calculate degrees
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
            degree[from]++;
            degree[to]++;
        }

        queue<int> q; // Leaf nodes queue
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                q.push(i);

        // Remove leaf nodes layer by layer until remaining nodes are root nodes
        while (!q.empty()) {
            int size = q.size();
            if (size == n)
                break; // If all nodes are processed, stop
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                n--; // Remove current node from graph
                for (int next : adj[cur]) {
                    if (--degree[next] == 1)
                        q.push(next);
                    // Decrease degree of neighbors and add leaf nodes to queue
                }
            }
        }

        // Remaining nodes in queue are root nodes of minimum height trees
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};
