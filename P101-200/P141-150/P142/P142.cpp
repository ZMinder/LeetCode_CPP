#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) { //如果链表为空或者仅有一个不成环的结点
            return NULL;
        }
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while (fast && fast->next &&
               fast != slow) { //当fast走到尾结点或fast与slow相同跳出循环
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast || !fast->next) { //不成环
            return NULL;
        }
        //存在环
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;
    int n = 1;
    head = solution.detectCycle(head);
    cout << head->val << endl;
    return 0;
}