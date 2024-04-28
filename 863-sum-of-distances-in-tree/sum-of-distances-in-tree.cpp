class Solution {
public:

    void postOrderTraversal(int root, int parent, vector<int>&count, vector<int>&res, vector<int>adj[]) {

        for (int i=0;i<adj[root].size();i++) {
            int nb = adj[root][i];

            if (nb == parent) continue;
            postOrderTraversal(nb, root, count, res, adj);
            count[root]+=count[nb];
            res[root]+=count[nb]+res[nb];
        }
        count[root]++;
    }

    void preOrderTraversal(int root, int parent, vector<int>&count, vector<int>&res, 
        vector<int>adj[], int n) {
        for (int i=0;i<adj[root].size();i++) {
            int nb = adj[root][i];

            if (parent == nb) continue;

            res[nb] = res[root]- count[nb] + n-count[nb];
            preOrderTraversal(nb, root, count,res, adj, n);
        }

    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];

        for (int i=0;i<edges.size();i++) {
            int a =edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int>count(n,0);
        vector<int>res(n,0);

        postOrderTraversal(0,-1, count, res, adj);
        preOrderTraversal(0,-1,count,res,adj,n);

        return res;

    }
};