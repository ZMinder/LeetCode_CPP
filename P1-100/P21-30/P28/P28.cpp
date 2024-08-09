#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int strStr(string haystack, string needle) {
        int next[needle.size()] = {0};
        getNext(needle, next);
        int i = 0;
        int j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) { //匹配成功
                i++;
                j++;
            } else { //匹配失败
                if (j == 0) { //如果当前字符与needle第一个字符都不匹配 i++
                    i++;
                } else { //否则找到已经匹配子串的最长前后缀匹配长度
                         //与其下一个字符匹配
                    j = next[j - 1];
                }
            }
        }
        return j == needle.size() ? (i - needle.size()) : -1;
    }

    void getNext(string &needle, int *next) {
        int i = 1; //当前回合要填写next数组的下标
        int j = 0; //待比较字符的下标
        while (i < needle.size()) {
            if (needle[i] == needle[j]) {
                next[i++] = ++j;
            } else {
                if (j == 0) { //当前子串最后一个字符与第一个字符不匹配
                              //公共前后缀长度为0
                    next[i++] = 0;
                } else {
                    j = next[j - 1]; //在已经匹配的子串中找最长前后缀长度
                }
            }
        }
    }
};
int main() {
    string str = "ababcaababcaabc";
    string sub = "ababcaabc";
    Solution solution;
    int res = solution.strStr(str, sub);
    cout << res << endl;
    return 0;
}