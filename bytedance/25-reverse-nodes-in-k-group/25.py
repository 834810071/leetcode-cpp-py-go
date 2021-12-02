#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode],
                      k: int) -> Optional[ListNode]:
        hair = ListNode(0, head)
        pre = hair

        while head:
            tail = pre
            for i in range(k):
                tail = tail.next
                if not tail:
                    return hair.next

            nx = tail.next
            head, tail = self.rev(head, tail)
            pre.next = head
            tail.next = nx
            pre = tail
            head = tail.next
        return hair.next

    def rev(self, head: Optional[ListNode], tail: Optional[ListNode]):
        prev = tail.next
        p = head
        while prev != tail:
            nx = p.next
            p.next = prev
            prev = p
            p = nx
        return tail, head


if __name__ == '__main__':
    sol = Solution()