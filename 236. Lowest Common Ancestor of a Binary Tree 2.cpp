/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* key, vector<TreeNode*>& path)
    {
        if(root == nullptr)
            return false;
        path.push_back(root);
        if(root == key)
            return true;
        if(findPath(root->left, key, path))
        {
            return true;
        }
        
        if(findPath(root->right, key, path))
        {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;
        findPath(root, p, pPath);
        findPath(root, q, qPath);
        while(qPath.size() > pPath.size())
        {
            qPath.pop_back();
        }
        while(qPath.size() < pPath.size())
        {
            pPath.pop_back();
        }
        while(qPath.back()!= pPath.back())
        {
            qPath.pop_back();
            pPath.pop_back();
        }
        return pPath.back();
    }
};
