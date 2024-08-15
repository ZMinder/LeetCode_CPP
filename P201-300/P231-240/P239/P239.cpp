#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        //滑动窗口的左右两个指针
        int left = 0;
        int right = 0;
        deque<int> deque; //单调队列 降序排列
        vector<int> res;
        while (right < nums.size()) {
            while (!deque.empty() && nums[right] > nums[deque.back()]) {
                //比待加入窗口值小的弹出来
                deque.pop_back();
            }
            deque.push_back(right++);
            if ((right - left) == k) {
                res.push_back(nums[deque.front()]); //一个窗口结算
                if (deque.front() == left) { //当前窗口最大值就是窗口左边界
                    deque.pop_front();
                }
                left++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution solution;
    nums = solution.maxSlidingWindow(nums, k);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}