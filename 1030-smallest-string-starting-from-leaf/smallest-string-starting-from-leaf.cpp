class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string result = "";    // Initialize result string
        dfs(root, "", result); // Start depth-first search (DFS) traversal
        return result;         // Return the smallest leaf string found
    }

    void dfs(TreeNode* node, string current, string& result) {
        if (!node) {
            return; // Base case: null node
        }

        // Add current node's value to the beginning of the current string
        current = char('a' + node->val) + current;

        // If it's a leaf node
        if (!node->left && !node->right) {
            // Update result if current leaf string is smaller
            if (result.empty() || current < result) {
                result = current;
            }
        }
        dfs(node->left, current, result);  // Recurse left
        dfs(node->right, current, result); // Recurse right
    }
};
