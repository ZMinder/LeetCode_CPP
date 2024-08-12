#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } else if (stack.empty()) { //如果匹配到右括号，而此时栈为空
                return false;
            } else if ((s[i] == ')' && stack.top() == '(') ||
                       (s[i] == ']' && stack.top() == '[') ||
                       (s[i] == '}' && stack.top() == '{')) {
                //右括号必须与前一个左括号匹配
                stack.pop();
            } else {
                return false;
            }
        }
        //最终栈应为空
        return stack.empty();
    }
};
int main() {
    string str = "(]";
    Solution solution;
    cout << solution.isValid(str) << endl;
    return 0;
}