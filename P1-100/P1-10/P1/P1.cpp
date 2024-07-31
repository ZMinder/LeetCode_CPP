#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;//使用哈希表记录数字与下标的对应关系
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {//如果找到了，则结束循环
                return {i, map[target - nums[i]]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
int main() { return 0; }