#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        //直接平方，调用系统排序
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
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
    vector<int> nums = {-7, -3, 2, 3, 11};
    Solution solution;
    nums = solution.sortedSquares(nums);
    printVector(nums);
    return 0;
}