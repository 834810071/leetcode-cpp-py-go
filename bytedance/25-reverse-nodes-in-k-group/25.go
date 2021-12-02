package main

import ("fmt")

/**
 * Definition for singly-linked list.
 **/
type ListNode struct {
    Val int
    Next *ListNode
 }
 func reverseKGroup(head *ListNode, k int) *ListNode {
    hair := &ListNode{Next: head}
    pre := hair

    for head != nil {
        tail := pre
        for i := 0; i < k; i++ {
            tail = tail.Next
            if tail == nil {
                return hair.Next
            }
        }
        nx := tail.Next
        head, tail = rev(head, tail)
        tail.Next = nx
        pre.Next = head
        pre = tail
        head = tail.Next
    }
    return hair.Next
}

func rev(head *ListNode, tail *ListNode) (*ListNode, *ListNode) {
    prev := tail.Next
    p := head
    for prev != tail {
        nx := p.Next
        p.Next = prev
        prev = p
        p = nx   
    }
    return tail, head
}

func main() {
	node1 := &ListNode{Val: 1}
	node2 := &ListNode{Val: 2}
	node3 := &ListNode{Val: 3}
	node4 := &ListNode{Val: 4}
	node5 := &ListNode{Val: 5}
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	res := reverseKGroup(node1, 2)
	for res != nil {
		fmt.Print(res.Val, "->")
		res = res.Next
	}
	fmt.Println()
}