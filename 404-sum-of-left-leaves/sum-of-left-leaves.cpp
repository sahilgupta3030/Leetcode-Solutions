// Auxiiliary Space and O(depth of tree) recursion system stack space
class Solution {
public:
    int solve(TreeNode* curr, bool isLeft) {
        if (!curr) {
            return 0;
        }

        if (!curr->left && !curr->right && isLeft) {
            return curr->val;
        }

        return solve(curr->left, true) + solve(curr->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) { return solve(root, false); }
};

// class Solution {
// public:
//     int sum(TreeNode* curr, TreeNode* parent) {
//         if(!curr)
//             return 0;

//         int left  = sum(curr->left, curr);
//         int right = sum(curr->right, curr);

//         int sum = 0;
//         if(curr->left == NULL && curr->right == NULL) {
//             if(parent && parent->left == curr)
//                 sum += curr->val;
//         }

//         return left+right+sum;
//     }

//     // main function
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(!root)
//             return 0;
//         TreeNode* parent = NULL;
//         return sum(root, parent);
//     }
// };