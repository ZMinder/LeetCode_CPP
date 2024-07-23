#include <bits/stdc++.h>
using namespace std;
class MyLinkedList {
  public:
    int val;
    int length;
    MyLinkedList *next;
    MyLinkedList *end; //该链表的最后一个结点

    MyLinkedList() {
        this->val = -1; //表示无结点
        this->length = 0;
        this->next = NULL;
        this->end = NULL;
    }

    int get(int index) {
        if (index >= length || index < 0) { //下标无效
            return -1;
        }
        MyLinkedList *temp = this->next;
        while (index-- > 0) { //找到index位置的结点
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(this->length, val); }

    void addAtIndex(int index, int val) {
        if (index > length || index < 0) {
            return;
        }
        MyLinkedList *pre = this;
        while (index-- > 0) { //找到前驱结点
            pre = pre->next;
        }
        //实例化待插入结点
        MyLinkedList *next = new MyLinkedList();
        next->val = val;
        next->next = pre->next;
        if (pre->next == NULL) {
            this->end = next;
        }
        //插入到链表
        pre->next = next;
        this->length++;
    }

    void deleteAtIndex(int index) {
        if (index >= this->length || index < 0) {
            return;
        }
        MyLinkedList *pre = this;
        while (index-- > 0) { //找到前驱结点
            pre = pre->next;
        }
        pre->next = pre->next->next;
        if (pre->next == NULL) {
            this->end = pre;
        }
        this->length--;
    }
};
int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(2);
    myLinkedList.deleteAtIndex(1); // 现在，链表变为 1->3
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(3);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(5);
    myLinkedList.addAtTail(5);
    myLinkedList.get(5);           // 返回 2
    myLinkedList.deleteAtIndex(6); // 现在，链表变为 1->3
    myLinkedList.deleteAtIndex(4); // 现在，链表变为 1->3
    return 0;
}