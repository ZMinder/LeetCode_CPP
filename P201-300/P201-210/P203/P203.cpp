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
    ListNode *removeElements(ListNode *head, int val) {
        //删除相等的头结点
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        //删除中间部分相等的节点
        ListNode *temp = head;
        //temp != NULL 判断移除头结点相等的结点后是否为空
        while (temp != NULL && temp->next != NULL) { // temp->val != val
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
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
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    int val = 6;
    head = solution.removeElements(head, val);
    printList(head);
    return 0;
}