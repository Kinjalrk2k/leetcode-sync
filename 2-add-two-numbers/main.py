# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = None
        digit1 = l1
        digit2 = l2
        digitr = result

        overflow = 0
        while digit1 or digit2:
            digit_sum = None

            if digit1 and digit2:
                digit_sum = digit1.val + digit2.val + overflow

                digit1 = digit1.next
                digit2 = digit2.next

            elif digit1:
                digit_sum = digit1.val + overflow
                digit1 = digit1.next

            elif digit2:
                digit_sum = digit2.val + overflow
                digit2 = digit2.next

            overflow = 0
            if digit_sum >= 10:
                overflow = 1
                digit_sum = digit_sum % 10

            node = ListNode(digit_sum)
            if digitr:
                digitr.next = node
                digitr = digitr.next
            else:
                digitr = node
                result = digitr

        if overflow == 1:
            digitr.next = ListNode(1)

        return result

