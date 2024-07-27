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
    ListNode *swapPairs(ListNode *head) {
        if (!head || (!head->next)) { //链表为空或者只有一个节点
            return head;
        }
        ListNode *fast = head->next->next; //快指针
        ListNode *slow = head;             //慢指针
        ListNode *pre = NULL; //记录前一对相邻节点的尾节点
        head = head->next;    //记录最终的头节点
        while (slow) {
            //修改上一对相邻节点的尾节点指向
            if (pre) {
                pre->next = slow->next;
            }
            //交换相邻指针
            slow->next->next = slow;
            slow->next = fast;
            //快慢指针后移
            pre = slow;
            slow = fast;
            if (!slow || !slow->next) { //当slow为空时或者下一对只有一个节点 结束循环
                break;
            }
            fast = fast->next->next;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution solution;
    head = solution.swapPairs(head);
    printList(head);
    return 0;
}