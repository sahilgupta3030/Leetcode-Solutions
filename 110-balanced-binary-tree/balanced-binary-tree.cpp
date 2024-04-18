class Solution {
public:
    // Check if tree is balanced
    bool isBalanced(TreeNode* root) {
        // Return true if height is not -1
        return getHeight(root) != -1;
    }

    // Get height of tree
    int getHeight(TreeNode* root) {
        // Return 0 if NULL
        if (!root) return 0;

        // Get heights of subtrees
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);

        // Return -1 if unbalanced
        if (left_height == -1 || right_height == -1) return -1;

        // Check balance condition
        if (abs(left_height - right_height) > 1) return -1;

        // Return max height + 1
        return max(left_height, right_height) + 1;
    }
};
