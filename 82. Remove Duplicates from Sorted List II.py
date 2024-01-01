# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ret = None
        cur = None
        while head is not None:
            if head.next == None or head.next.val != head.val:
                if ret == None:
                    ret = ListNode(head.val)
                    cur = ret
                else:
                    cur.next = ListNode(head.val)
                    cur = cur.next
                head = head.next
            else:
                val = head.val
                while head != None and head.val == val:
                    head = head.next
        return ret
