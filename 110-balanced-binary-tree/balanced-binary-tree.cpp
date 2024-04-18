class Solution {
public:
    // calculate the height of the tree
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return max(height(root->left), height(root->right)) + 1;
    }

    // function to perform inorder traversal and check balance
    void inorderUtil(TreeNode* root, bool& ans) {
        if (root != NULL) {
            inorderUtil(root->left, ans); // Traverse left subtree

            // Calculate heights of left and right subtrees
            int lh = height(root->left);
            int rh = height(root->right);

            // if diff in heights more than 1..
            // then mark tree as unbalanced
            if (abs(lh - rh) > 1)
                ans = ans && false;

            inorderUtil(root->right, ans); // Traverse right subtree
        }
    }

    // Main function
    bool isBalanced(TreeNode* root) {
        bool ans = true;        // Initialize answer as true
        inorderUtil(root, ans); // Call utility function to check balance
        return ans;             // Return the final answer
    }
};