#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string reverseWords(string s) {
        //去除前导空格和尾随空格
        int start = 0;
        while (s[start] == ' ') {
            start++;
        }
        int end = s.size() - 1;
        while (s[end] == ' ') {
            end--;
        }
        string res;
        while (start <= end) {
            if (s[start] != ' ' || (s[start] == ' ' && s[start - 1] != ' ')) {
                res.append(string(1, s[start]));
            }
            start++;
        }
        reverse(res.begin(), res.end());
        int pre = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == ' ') {
                reverse(res.begin() + pre, res.begin() + i);
                pre = i + 1;
            }
        }
        reverse(res.begin() + pre, res.end());
        return res;
    }
};
int main() {
    string s = "a good   example";
    Solution solution;
    s = solution.reverseWords(s);
    cout << s << endl;
    return 0;
}