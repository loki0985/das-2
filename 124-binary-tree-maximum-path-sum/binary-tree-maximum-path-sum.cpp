/*
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // Ignore negative paths
        int leftSum = max(0, solve(root->left));
        int rightSum = max(0, solve(root->right));

        // Path passing through current node
        int currentPath = root->val + leftSum + rightSum;

        // Update global maximum
        ans = max(ans, currentPath);

        // Return best single-side path to parent
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};