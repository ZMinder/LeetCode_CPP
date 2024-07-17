#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0;                //左侧是与val不相等的数
        int right = nums.size() - 1; //右侧是与val相等的数
        while (left <= right) {
            if (nums[left] == val) { //如果相等，放在右边界（可以省略，直接把右边界未比较的数放到左边界即可），右边界左移
                nums[left] = nums[right--];
            } else { //如果不等，左边界右移
                left++;
            }
        }
        return left;
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