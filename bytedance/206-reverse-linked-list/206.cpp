#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head == nullptr) {
            return head;
        }

        ListNode *nextNode = head->next, *curNode = head;
        curNode->next = nullptr;
        while (nextNode != nullptr) {
            ListNode *tmpNode = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = tmpNode;
        }
        return curNode;
    }
};

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    Solution s = Solution();
    ListNode* res = s.reverseList(node1);
    while (res){
        cout << res << " -> ";
        res = res->next;
    }
    
    return 0;
}