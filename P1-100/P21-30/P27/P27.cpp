#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {//采用快慢指针，慢指针左侧是不相等的数
    //快指针只关注不相等的数，将其放到慢指针的位置
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
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