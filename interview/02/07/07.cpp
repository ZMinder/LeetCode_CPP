#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //假设两者长度分别为x和y，相交的长度为z
        //两段链表的长度之差a必然存在于不相交的区域
        //较长的链表先走a步，然后两者同时开始走，最后必然在相交点撞上
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        int sub = abs(lengthA - lengthB); //求取两者差值
        ListNode *large = lengthA > lengthB ? headA : headB;
        ListNode *small = large == headA ? headB : headA;
        while (sub-- > 0) { //较长的链表先走sub步
            large = large->next;
        }
        while (large != small) { //两者同时走，知道相交
            large = large->next;
            small = small->next;
        }
        return large;
    }

    int getLength(ListNode *head) { //获取链表的长度
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
};