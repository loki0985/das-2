/*
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int current) {
        if (node == nullptr)
            return 0;

        // Build the number while traversing
        current = current * 10 + node->val;

        // If leaf node, return the formed number
        if (node->left == nullptr && node->right == nullptr)
            return current;

        // Sum left and right subtree paths
        return dfs(node->left, current) + dfs(node->right, current);
    }
};