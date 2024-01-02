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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ret = new ListNode();
        ListNode* tail = ret;
        ListNode* first = head;
        ListNode* last = head;
        while (head != nullptr) {
            first = head;
            for (int i = 0; i < k; i++) {
                if (head == nullptr) {
                    tail->next = first;
                    return ret->next;
                }
                last = head;
                head = head->next;
            }
            last->next = nullptr;
            ListNode* prev = nullptr;
            ListNode* tmp_first = first;
            while (first != nullptr) {
                ListNode* next = first->next;
                first->next = prev;
                prev = first;
                first = next;
            }
            tail->next = last;
            tail = tmp_first;
        }

        return ret->next;
    }
};
