#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, bool> map;
        for (int i = 0; i < nums1.size();
             i++) { //将nums1中的数加入哈希表并标记为false
            map[nums1[i]] = false;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (map.find(nums2[i]) != map.end()) { //将交集标记为true
                map[nums2[i]] = true;
            }
        }
        vector<int> res;
        for (unordered_map<int, bool>::iterator iter = map.begin();
             iter != map.end(); iter++) {
            if (iter->second) { //将标记为true的交集添加进结果集合
                res.push_back(iter->first);
            }
        }
        return res;
    }
};
int mian() { return 0; }