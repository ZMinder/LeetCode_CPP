#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        int n = nums1.size();
        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[nums3[i] + nums4[j]]++; //记录后面两个数组的累加和及其次数
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                if (map.find(-sum) != map.end()) {
                    count += map[-sum];
                }
            }
        }
        return count;
    }
};
int main() { return 0; }