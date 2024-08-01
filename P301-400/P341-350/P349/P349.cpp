#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        //先对两个集合进行排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //然后采用双指针进行扫描
        int i = 0;
        int j = 0;
        int pre = -1; //表示前一个加入结果集的元素
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                if (nums1[i] != pre) { //与前一个加入结果集合的元素不同
                    res.push_back(nums1[i]);
                    pre = nums1[i];
                }
                i++;
                j++;
            }
        }
        return res;
    }
};
int main() { return 0; }