#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        int next[length];
        getNext(s, next);
        if (!next[length - 1]) { //最长公共前后缀长度为0 说明没有重复子串
            return false;
        }
        //假设s由n个x构成，最长公共前后缀长度为m个x，n-m=1
        return length % (length - next[length - 1]) == 0;
    }

    void getNext(string &str, int *next) {
        next[0] = 0;
        int i = 1;
        int j = 0;
        while (i < str.size()) {
            if (str[i] == str[j]) {
                next[i++] = ++j;
            } else {
                if (j == 0) {
                    next[i++] = 0;
                } else {
                    j = next[j - 1];
                }
            }
        }
    }
};
int main() {
    string str = "abab";
    Solution solution;
    cout << solution.repeatedSubstringPattern(str) << endl;
    return 0;
}