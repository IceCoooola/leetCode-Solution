/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        Node* ret = new Node(node->val);
        mp[node] = ret;
        vector<Node*> neighbors;
        for (auto n : node->neighbors) {
            if (mp.find(n) != mp.end()) {
                neighbors.push_back(mp[n]);
            } else {
                neighbors.push_back(cloneGraph(n));
            }
        }
        ret->neighbors = neighbors;
        return ret;
    }
};
