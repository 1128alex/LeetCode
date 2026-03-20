/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int max = 0;
public:
    int findDepth(TreeNode* root) {
        if (!root) return 0;

        int left = findDepth(root->left);
        int right = findDepth(root->right);
        int add = left + right;
        
        if (max < add) {
            max = add;
        }
        
        return 1 + std::max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findDepth(root);
        return max;
    }
};