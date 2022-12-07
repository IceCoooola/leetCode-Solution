/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _invertTree(struct TreeNode* root)
 {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    _invertTree(root->left);
    _invertTree(root->right);
 }

struct TreeNode* invertTree(struct TreeNode* root){
    _invertTree(root);
    return root;
}
