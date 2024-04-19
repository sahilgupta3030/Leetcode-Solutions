class Solution {
public:
    // Function to merge two binary trees
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If both trees are empty, return nullptr
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;

        // Calculate the value of the new node
        const int val = (root1 == nullptr ? 0 : root1->val) +
                        (root2 == nullptr ? 0 : root2->val);

        // Create a new node with the calculated value
        TreeNode* root = new TreeNode(val);

        // Recursively merge the left subtrees
        root->left = mergeTrees(root1 == nullptr ? nullptr : root1->left,
                                root2 == nullptr ? nullptr : root2->left);

        // Recursively merge the right subtrees
        root->right = mergeTrees(root1 == nullptr ? nullptr : root1->right,
                                 root2 == nullptr ? nullptr : root2->right);

        // Return the merged tree
        return root;
    }
};
