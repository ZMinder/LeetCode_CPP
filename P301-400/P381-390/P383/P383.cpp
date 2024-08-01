#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        int map[26] = {0}; //字符串中只出现小写字母，可以使用数组代替哈希表
        for (int i = 0; i < magazine.size(); i++) {
            //优先统计magazine中字符的个数
            map[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); j++) {
            //遍历ransomNote，并让map中对应字符次数自减
            map[ransomNote[j] - 'a']--;
            if (map[ransomNote[j] - 'a'] < 0) {
                //如果该字符次数小于0，说明magazine无法构成ransomNote的该字符
                return false;
            }
        }
        return true;
    }
};
int main() {
    string ransomNote = "aa";
    string magazine = "aab";
    Solution solution;
    cout << solution.canConstruct(ransomNote, magazine) << endl;
    return 0;
}