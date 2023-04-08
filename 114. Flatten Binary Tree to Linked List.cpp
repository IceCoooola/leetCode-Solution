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
    void flatten(TreeNode* root) {
        if(!root)
        return;
        queue<TreeNode*> q;
        inOrder(root,q);
        q.front()->left = nullptr;
        TreeNode* prev = q.front();
        q.pop();
        while(!q.empty())
        {
            q.front()->left = nullptr;
            prev->right = q.front();
            prev = q.front();
            q.pop();
        }
    }

    void inOrder(TreeNode* root, queue<TreeNode*>& q)
    {
        if(!root)
            return;
        q.push(root);
        inOrder(root->left, q);
        inOrder(root->right, q);
    }
};
