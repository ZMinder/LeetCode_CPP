#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0;                //左侧是与val不相等的数
        int right = nums.size() - 1; //右侧是与val相等的数
        while (left <= right) {
            if (nums[left] == val) { //如果相等放在右边界，右边界左移
                swap(nums, left, right);
                right--;
            } else { //如果不等，左边界右移
                left++;
            }
        }
        return left;
    }

    //交换两个数
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

//打印vector
void printVector(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int target = 2;
    Solution solution;
    solution.removeElement(nums, target);
    printVector(nums);
    return 0;
}