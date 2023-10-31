# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        dic = set()
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        
        while head:
            if head.val in dic:
                prev.next = head.next
            else:
                dic.add(head.val)
                prev = head
            head = head.next
        
        return dummy.next