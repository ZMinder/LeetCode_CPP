#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0;  //子数组左边界
        int right = 0; //子数组右边界下一个
        long sum = 0;  //累加和
        int minLength = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right++];//sum < target 右扩
            while(sum >= target){//左边界右扩直到sum < target
                minLength = min(minLength, right - left);//统计子数组长度最小值
                sum -= nums[left++];
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