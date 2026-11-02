# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        current = head
        count = 1
        while current.next:
            count += 1
            current = current.next

        current = head
        left = None
        for i in range(0, count - n):
            left = current
            current = current.next

        if left:
            left.next = current.next
            current.next = None
        elif head.next:
            head = head.next
        else:
            head = None

        return head