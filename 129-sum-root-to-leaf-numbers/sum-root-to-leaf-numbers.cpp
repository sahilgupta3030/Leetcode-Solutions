class Solution {
public:

    int sumRec(TreeNode* root, int last)
    {
        if(root->left==NULL && root->right==NULL)
            return root->val + last;
        int res = 0;
        if(root->left)
        {
            res += sumRec(root->left, (root->val+last)*10);
        }
        if(root->right)
        {
            res += sumRec(root->right, (root->val+last)*10);
        }
        return res;
    }

    int sumNumbers(TreeNode* root) {
        return sumRec(root, 0);
    }
};