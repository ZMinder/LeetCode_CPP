#include <bits/stdc++.h>
using namespace std;
class MyStack {
  private:
    queue<int> *real;
    queue<int> *help;

    void real2help() {
        while (real->size() > 1) {
            help->push(real->front());
            real->pop();
        }
    }

    void queueSwap() {
        queue<int> *temp = real;
        real = help;
        help = temp;
    }

  public:
    MyStack() {
        real = new queue<int>();
        help = new queue<int>();
    }

    void push(int x) { real->push(x); }

    int pop() {
        real2help();
        int last = real->front();
        real->pop();
        queueSwap();
        return last;
    }

    int top() {
        real2help();
        int last = real->front();
        help->push(last);
        real->pop();
        queueSwap();
        return last;
    }

    bool empty() { return real->empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() { return 0; }