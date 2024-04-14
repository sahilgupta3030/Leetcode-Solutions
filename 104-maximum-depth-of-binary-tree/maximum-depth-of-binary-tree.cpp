class Solution {
public:
    int maxDepth(TreeNode* root) {
        // If the tree is empty, its depth is 0
        if (root == nullptr)
            return 0;

        // Queue to store nodes for BFS traversal
        queue<TreeNode*> nodes;
        // Start with the root node
        nodes.push(root);
        // Initialize depth to 0
        int depth = 0;

        // Perform BFS traversal
        while (!nodes.empty()) {
            // Increment depth for each level
            depth++;
            // Get the number of nodes at the current level
            int size = nodes.size();
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                // Get the front node and remove it from the queue
                TreeNode* poppedNode = nodes.front();
                nodes.pop();
                // Add child nodes to the queue for the next level
                if (poppedNode->left != nullptr)
                    nodes.push(poppedNode->left);
                if (poppedNode->right != nullptr)
                    nodes.push(poppedNode->right);
            }
        }

        // Return the maximum depth of the tree
        return depth;
    }
};
