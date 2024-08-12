#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string removeDuplicates(string s) {
        string res;
        //利用string本身存在的栈特性替代栈
        for (int i = 0; i < s.size(); i++) {
            if (res.empty()) {
                res.push_back(s[i]);
            } else if (res.back() == s[i]) {
                res.pop_back();
            } else {
                (res.push_back(s[i]));
            }
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