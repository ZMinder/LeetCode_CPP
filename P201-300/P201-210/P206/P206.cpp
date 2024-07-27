#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;  //前驱结点
        ListNode *next = NULL; //后继结点
        while (head) {
            next = head->next; //拿到后继结点
            head->next = pre;  //修改head的next指针
            pre = head;        // pre后移
            head = next;       // head后移
        }
        return pre;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution solution;
    head = solution.reverseList(head);
    printList(head);
    return 0;
}