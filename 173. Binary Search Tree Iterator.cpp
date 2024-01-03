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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        int ret = data[i++];
        return ret;
    }
    
    bool hasNext() {
        return i != n;
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        data.push_back(root->val);
        traverse(root->right);
        n += 1;
    }
    vector<int> data;
    int i = 0;
    int n = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
