/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        queue<Node*> v;
        v.push(root);
        int levelNode = 1;
        while(!v.empty())
        {
            
            Node* front = v.front();
            if(front->left)
            {
            v.push(front->left);
            v.push(front->right);                
            }
            v.pop();
            --levelNode;
            if(!levelNode)
            {
                front->next = nullptr;
                levelNode = v.size();
            }
            else
            {
                front->next = v.front();
            }
        }
        return root;
    }
};
