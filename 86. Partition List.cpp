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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ret = new ListNode();
        ListNode* ret_tail = ret;
        ListNode* tail = new ListNode();
        ListNode* tail_tail = tail;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = nullptr;
            if (head->val < x) {
                ret_tail->next = head;
                ret_tail = head;
            } else {
                tail_tail->next = head;
                tail_tail = head;
            }
            head = next;
        }
        ret_tail->next = tail->next;
        return ret->next;
    }
};
