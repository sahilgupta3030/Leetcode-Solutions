class Solution {
private:
    int sum = 0;

public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        getNumber(root, 0);
        return this->sum;
    }

private:
    void getNumber(TreeNode* node, int num) {
        int cur = num * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += cur;
            return;
        }
        if (node->left != nullptr)
            getNumber(node->left, cur);
        if (node->right != nullptr)
            getNumber(node->right, cur);
    }
};