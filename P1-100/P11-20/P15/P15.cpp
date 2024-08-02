#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        //为了三元组不重复，可以将数组排序，有效避免某个数被三元组的同一位置重复选中
        sort(nums.begin(), nums.end());
        //保证三元组的下标必须是递增的，避免出现重复的三元组
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { //跳过重复数字
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < nums.size() - 1 &&
                           nums[left] == nums[left + 1]) { //避免重复
                        left++;
                    }
                    left++;
                }
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    vector<vector<int>> res = solution.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}