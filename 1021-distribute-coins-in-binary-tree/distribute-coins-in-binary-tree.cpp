class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    // returns the number of coins I can give (positive) / take (negative).
    int dfs(TreeNode* root, int& ans) {
        if (root == nullptr)
            return 0;

        // excess coins from the left &right subtree..
        const int l = dfs(root->left, ans);
        const int r = dfs(root->right, ans);

        // total moves is the sum of absolute excess from left and right
        ans += abs(l) + abs(r);
        return (root->val - 1) + l + r;
    }
};