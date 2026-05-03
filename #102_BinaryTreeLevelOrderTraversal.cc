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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> queue;
        queue.push_back(root);
        while (queue.size() != 0) {
            vector<TreeNode*> new_queue;
            vector<int> temp;
            for (TreeNode* item : queue) {
                if (item != nullptr) {
                    temp.push_back(item->val);
                    new_queue.push_back(item->left);
                    new_queue.push_back(item->right);
                }
            }
            if (temp.size() > 0) {
                res.push_back(temp);
            }
            queue = new_queue;
        }
        return res;
    }
};