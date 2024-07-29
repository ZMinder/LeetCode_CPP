#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { //两个字符串长度不等 必然不会成为字母异位词
            return false;
        }
        //使用数组记录每个字母的出现次数（题目说明仅包含小写字母）
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        //判断是否全为0
        for (int i = 0; i < 26; i++) {
            if (arr[i]) {//如果非0 说明不是字母异位词
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    cout << solution.isAnagram(s, t) << endl;
    return 0;
}