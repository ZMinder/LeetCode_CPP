#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size() / (2 * k); i++) { //可以凑出的2k有多少组
            reverse(s.begin() + (2 * i * k), s.begin() + (2 * i + 1) * k);
        }
        //剩余的不到2k个
        int rest = s.size() % (2 * k);
        if (rest < k) {
            reverse(s.end() - rest, s.end());
        } else {
            reverse(s.end() - rest, s.end() - rest + k);
        }
        return s;
    }
};
int main() {
    string s = "abcdefghijk";
    int k = 2;
    Solution solution;
    s = solution.reverseStr(s, k);
    cout << s << endl;
    return 0;
}