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
        if(root == nullptr)
            return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<int> levelv;
        vector<vector<int>> retvv;
        q.push(root);
        int levelnode = 1;
        while(!q.empty())
        {
            if(q.front()->left)
            {
                q.push(q.front()->left);   
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
            }    
            levelv.push_back(q.front()->val);
            q.pop();
            --levelnode;
            if(levelnode == 0)
            {
                retvv.push_back(levelv);
                levelv.clear();
                levelnode = q.size();
            }
        }
        return retvv;
    }
};
