#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<string> commonChars(vector<string> &words) {
        int minCount[26];
        fill(minCount, minCount + 26, INT_MAX);
        int count[26] = {0};
        for (int i = 0; i < words.size(); i++) {
            fill(count, count + 26, 0);
            for (int j = 0; j < words[i].size(); j++) {
                count[words[i][j] - 'a']++; //统计每个字符串中字符出现的次数
            }
            //与minCount中进行比较，取较小值
            for (int j = 0; j < 26; j++) {
                minCount[j] = min(minCount[j], count[j]);
            }
        }
        //数组中保留字符在所有字符串中出现的最小次数
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minCount[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
int main() {
    Solution solution;
    vector<string> arr = {"cool", "lock", "cook"};
    vector<string> res = solution.commonChars(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}