#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        int negative = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) { //获取到0所在的位置,0左侧递减，右侧递增
                negative = i;
            }
            nums[i] *= nums[i];
        }
        //采用类似归并排序的归并操作
        int left = negative == -1 ? -1 : 0; //负数部分平方后最大值
        int right = nums.size() - 1;        //正数部分平方后最大值
        if (negative != -1) {
            vector<int> temp(nums.size());
            int index = nums.size() - 1; //末尾下标，从后往前填
            while (left <= right) {
                if (nums[left] <= nums[right]) {
                    temp[index--] = nums[right--];
                } else {
                    temp[index--] = nums[left++];
                }
            }
            //拷贝到原数组
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = temp[i];
            }
        }
        return nums;
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
    vector<int> nums = {-5, -3, -2, -1};
    Solution solution;
    nums = solution.sortedSquares(nums);
    printVector(nums);
    return 0;
}