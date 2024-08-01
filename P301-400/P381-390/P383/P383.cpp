#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        //使用哈希表统计ransomNote中字符出现的次数
        unordered_map<char, int> map;
        for (int i = 0; i < ransomNote.size(); i++) {
            map[ransomNote[i]]++;
        }
        //统计magazine中字符出现的次数，在map中自减
        for (int j = 0; j < magazine.size(); j++) {
            map[magazine[j]]--;
            if (map[magazine[j]] <= 0) { //如果自减完后<=0，从哈希表中删除
                map.erase(magazine[j]);
            }
        }
        //如果ransomNote能由magazine组成，最终哈希表会为空（因为magazine字符至少会比ransomNote相等）
        return map.empty();
    }
};
int main() {
    string ransomNote = "aa";
    string magazine = "aab";
    Solution solution;
    cout << solution.canConstruct(ransomNote, magazine) << endl;
    return 0;
}