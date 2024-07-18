#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0;  //子数组左边界
        int right = 0; //子数组右边界下一个
        long sum = 0;  //累加和
        int minLength = INT_MAX;
        while (right != nums.size() || sum >= target) {
            //子数组右边界已经到达nums末尾，并且累加和小于target
            //说明后续累加和不可能大于等于target
            if (sum >= target) { //当前子数组累加和已经大于等于target left右移
                minLength = min(minLength, right - left); //统计子数组长度最小值
                sum -= nums[left++];
            } else if (right < nums.size()) {
                //当前子数组累加和小于target right右移
                sum += nums[right++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 11;
    Solution solution;
    int res = solution.minSubArrayLen(target, nums);
    cout << res << endl;
    return 0;
}