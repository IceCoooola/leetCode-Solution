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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        ListNode* tail = head;
        int n = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        k = n - k;
        ListNode* cur = head;
        while (--k) {
            cur = cur->next;
        }
        ListNode* next = cur->next;
        cur->next = nullptr;
        tail->next = head;
        return next;
    }
};
