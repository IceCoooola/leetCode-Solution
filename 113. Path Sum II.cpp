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
    vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return ret;
        helper(root, targetSum, {});
        return ret;
    }

    void helper(TreeNode* root, int targetSum, vector<int> path) {
        if (is_leaf(root)) {
            if (root->val == targetSum) {
                path.push_back(root->val);
                ret.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if(root->left) helper(root->left, targetSum, path);
        if (root->right) helper(root->right, targetSum, path);
    }
    
    bool is_leaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};
