#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                stack.push(cal(stack, tokens[i][0]));
            } else { //数字直接入栈
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }

    int cal(stack<int> &stack, char ch) {
        int second = stack.top();
        stack.pop();
        int first = stack.top();
        stack.pop();
        int res = 0;
        switch (ch) {
        case '+':
            res = first + second;
            break;
        case '-':
            res = first - second;
            break;
        case '*':
            res = first * second;
            break;
        case '/':
            res = first / second;
            break;
        }
        return res;
    }
};
int main() {
    Solution solution;
    vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                             "/",  "*", "17", "+", "5", "+"};
    int res = solution.evalRPN(tokens);
    cout << res << endl;
    return 0;
}