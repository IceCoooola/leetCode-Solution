/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        if (l.size() == 0) {
            return nullptr;
        }
        while (l.size() > 1) {
            ListNode* a = l.back();
            l.pop_back();
            ListNode* b = l.back();
            l.pop_back();
            l.push_back(mergeTwo(a, b));   
        }
        return l[0];
    }
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode* ret = new ListNode();
        ListNode* cur = ret;
        while (a || b) {
            ListNode* next = a;
            if (!next || (b && b->val < a->val)) {
                next = b;
                b = b->next;
                next->next = nullptr;
                cur->next = next;
                cur = next;
            } else {
                a = a->next;
                next->next = nullptr;
                cur->next = next;
                cur = next;
            }
        }
        return ret->next;
    }
};
