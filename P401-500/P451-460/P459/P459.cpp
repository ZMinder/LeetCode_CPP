#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        str.erase(str.end() - 1); //去尾
        return str.find(s, 1) != -1;//从下标为1的位置开始查找，相当于去头
    }
};
int main() {
    string str = "aabaaba";
    Solution solution;
    cout << solution.repeatedSubstringPattern(str) << endl;
    return 0;
}