#include <bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (n-- > 0) { //快指针先走n步
            fast = fast->next;
        }
        if (!fast) { //删除头结点
            return head->next;
        }
        //快慢指针同时移动
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        //此时slow指向待删除节点的前驱节点
        slow->next = slow->next->next;
        return head;
    }
};

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    int n = 1;
    head = solution.removeNthFromEnd(head, n);
    printList(head);
    return 0;
}