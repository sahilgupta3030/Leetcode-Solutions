class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if (root == NULL) {
            return NULL; // return NULL for empty subtree
        }

        // recursively remove left and right leaf nodes
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // remove current node if it's a target leaf
        if (root->left == NULL && root->right == NULL && root->val == target) {
            return NULL;
        }

        // return the modified tree
        return root;
    }
};
