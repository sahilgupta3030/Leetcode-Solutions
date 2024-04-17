class Solution {
public:
    string smallestLeafString = "";

    string smallestFromLeaf(TreeNode* root) {
        string path = "";          // Initialize path during DFS
        dfs(root, path);           // Depth-first search traversal
        return smallestLeafString; // Return smallest leaf string
    }

    void dfs(TreeNode* node, string& path) {
        if (!node)
            return; // Base case: null node

        path += 'a' + node->val; // Add node value to path

        if (!node->left && !node->right) { // Leaf node check
            string pathReversed = path;    // Copy path
            reverse(pathReversed.begin(),
                    pathReversed.end()); // Reverse for leaf string
            if (smallestLeafString.empty() ||
                pathReversed < smallestLeafString) {
                // Update smallest leaf string if necessary
                smallestLeafString = pathReversed;
            }
        }

        dfs(node->left, path);  // Recurse left
        dfs(node->right, path); // Recurse right

        path.pop_back(); // Backtrack
    }
};
