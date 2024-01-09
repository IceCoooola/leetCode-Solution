# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        n = len(lists)
        ret = ListNode(0)
        ptr = ret
        flag = True
        while flag:
            cur = 0
            flag = False
            for i in range(n):
                if (lists[cur] == None and lists[i] is not None) or (lists[i] is not None and lists[i].val <= lists[cur].val):
                    flag = True
                    cur = i
            if lists[cur] == None:
                break
            tmp = lists[cur]
            lists[cur] = lists[cur].next
            tmp.next = None
            ptr.next = tmp
            ptr = ptr.next
        return ret.next
