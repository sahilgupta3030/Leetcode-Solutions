class Solution {
public:
    vector<int> findMinHeightTrees(int numNodes, vector<vector<int>>& edges) {
        if (numNodes == 1) return {0};
        vector<vector<int>> adjacencyList(numNodes);
        vector<int> degrees(numNodes, 0);
        for (const auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
            degrees[nodeA]++;
            degrees[nodeB]++;
        }
        queue<int> processingQueue;
        for (int i = 0; i < numNodes; ++i) {
            if (degrees[i] == 1) {
                processingQueue.push(i);
            }
        }
        vector<int> minHeightRoots;
        while (!processingQueue.empty()) {
            minHeightRoots.clear();
            int levelSize = processingQueue.size(); 
            for (int i = 0; i < levelSize; ++i) {
                int currentNode = processingQueue.front();
                processingQueue.pop();
                minHeightRoots.push_back(currentNode);
                for (int adjacentNode : adjacencyList[currentNode]) {
                    if (--degrees[adjacentNode] == 1) { 
                        processingQueue.push(adjacentNode);
                    }
                }
            }
        }
        return minHeightRoots;
    }
};
