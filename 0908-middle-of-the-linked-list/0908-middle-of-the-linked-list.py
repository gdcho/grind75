# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize two pointers, slow and fast.
        slow = head
        fast = head
        
        # Traverse the list with slow moving one step at a time
        # and fast moving two steps at a time.
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        
        # When fast reaches the end of the list, slow will be at the middle.
        return slow
        