#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    //二分查找
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; //未找到目标数
    }
};
int main() {
    vector<int> nums = {-1};
    int target = 2;
    Solution solution;
    int res = solution.search(nums, target);
    cout << res << endl;
    return 0;
}