#include <bits/stdc++.h>
using namespace std;
class MyQueue {
  private:
    stack<int> *in;
    stack<int> *out;

    void in2out() {
        while (!in->empty()) { //将in栈倒入out栈
            out->push(in->top());
            in->pop();
        }
    }

  public:
    MyQueue() { //初始化两个栈
        in = new stack<int>();
        out = new stack<int>();
    }

    void push(int x) { in->push(x); }

    int pop() {
        if (out->empty()) { //将in栈倒入out栈
            in2out();
        }
        int temp = out->top();
        out->pop();
        return temp;
    }

    int peek() {
        if (out->empty()) { //将in栈倒入out栈
            in2out();
        }
        return out->top();
    }

    bool empty() { return in->empty() && out->empty(); }
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