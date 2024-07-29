#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { //两个字符串长度不等 必然不会成为字母异位词
            return false;
        }
        //使用哈希表记录每个字母的出现次数
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++) { //统计s字符串中每个字母出现的次数
            map[s[i]]++;
            map[t[i]]--;
        }
        for (unordered_map<char, int>::iterator iter = map.begin();
             iter != map.end(); iter++) {
            if (iter->second != 0) { //如果存在不为0的字母 必然不是字母异位词
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