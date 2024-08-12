#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for (int i = s.size() - 1; i >= 0; i--) {
            //从后往前扫描，保证最后清空栈时字符串是正序
            if (stack.empty()) {
                stack.push(s[i]); //如果栈为空，说明i之前字符全部删除
            } else if (stack.top() == s[i]) {
                //如果当前字符与栈顶字符相同，说明遇到重复字符
                stack.pop();
            } else { //如果不同，说明要添加到最终字符串中
                stack.push(s[i]);
            }
        }
        string res;
        while (!stack.empty()) {
            res.append(string(1, stack.top()));
            stack.pop();
        }
        return res;
    }
};
int main() {
    string str = "abbaca";
    Solution solution;
    cout << solution.removeDuplicates(str) << endl;
    return 0;
}