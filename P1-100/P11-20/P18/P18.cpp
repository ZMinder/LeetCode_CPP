#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end()); //对数组进行升序排序
        for (int i = 0; i < nums.size() - 3; i++) { //第一个数
            if (i > 0 && nums[i] == nums[i - 1]) {
                //避免四元组某个位置出现同一个数
                continue;
            }
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] >
                target) {
                //最小的四数之和都大于target，说明后续没有满足条件的
                break;
            }
            if ((long)nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] +
                    nums[nums.size() - 3] <
                target) {
                // nums[i]加上最大的三个小于target，说明nums[i]加上后续无法等于target
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) { //第二个数
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] >
                    target) {
                    //最小的四数之和都大于target，说明后续没有满足条件的
                    break;
                }
                if ((long)nums[i] + nums[nums.size() - 1] +
                        nums[nums.size() - 2] + nums[j] <
                    target) {
                    // nums[i]加上最大的三个小于target，说明nums[i]加上后续无法等于target
                    continue;
                }
                int right = nums.size() - 1;            //第四个数
                for (int left = j + 1; left < right;) { //第三个数
                    if (left > j + 1 && nums[left] == nums[left - 1]) {
                        left++;
                        continue;
                    }
                    long sum =
                        (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else {
                        if (sum == target) {
                            res.push_back(
                                {nums[i], nums[j], nums[left], nums[right]});
                        }
                        left++;
                    }
                }
            }
        }
        return res;
    }
};
int main() {
    vector<int> arr = {1000000000, 1000000000, 1000000000, 1000000000};
    int target = 8;
    Solution solution;
    vector<vector<int>> res = solution.fourSum(arr, target);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}