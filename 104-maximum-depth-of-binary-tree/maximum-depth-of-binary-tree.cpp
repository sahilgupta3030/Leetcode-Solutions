class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> nodes;
        nodes.push(root);
        int levels = 0;

        while (!nodes.empty()) {
            levels++;
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                TreeNode* poppedNode = nodes.front();
                nodes.pop();
                if (poppedNode->left != nullptr)
                    nodes.push(poppedNode->left);
                if (poppedNode->right != nullptr)
                    nodes.push(poppedNode->right);
            }
        }

        return levels;
    }
};