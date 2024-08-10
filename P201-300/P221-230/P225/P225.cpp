#include <bits/stdc++.h>
using namespace std;
class MyStack {
  private:
    queue<int> *real;
    queue<int> *help;

  public:
    MyStack() {
        real = new queue<int>();
        help = new queue<int>();
    }

    void push(int x) {
        help->push(x);
        while (!real->empty()) {
            help->push(real->front());
            real->pop();
        }
        swap(real, help);
    }

    int pop() {
        int temp = real->front();
        real->pop();
        return temp;
    }

    int top() { return real->front(); }

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