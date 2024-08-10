#include <bits/stdc++.h>
using namespace std;
class MyQueue {
  private:
    stack<int> *help;
    stack<int> *real;

  public:
    MyQueue() { //初始化两个栈
        help = new stack<int>();
        real = new stack<int>();
    }

    void push(int x) {
        while (!real->empty()) { //当实际用于存储的栈非空时，将其倒入辅助栈
            help->push(real->top());
            real->pop();
        }
        //将给定元素压入栈底
        real->push(x);
        while (!help->empty()) {
            //将辅助栈的元素压入实际存储的栈，并且保证弹出的顺序满足队列规则
            real->push(help->top());
            help->pop();
        }
    }

    int pop() {
        int temp = real->top();
        real->pop();
        return temp;
    }

    int peek() { return real->top(); }

    bool empty() { return real->empty(); }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek();  // return 1
    myQueue.pop();   // return 1, queue is [2]
    myQueue.empty(); // return false
    return 0;
}