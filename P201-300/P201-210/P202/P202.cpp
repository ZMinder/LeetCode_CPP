#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> set; //使用HashSet记录每次平方和的结果，防止出现循环
        while (n != 1 && set.find(n) == set.end()) {
            set.insert(n);
            n = bitSum(n);
        }
        return n == 1;
    }

    int bitSum(int n) { //求取各位的平方和
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
int main() {
    int n = 19;
    Solution solution;
    bool res = solution.isHappy(n);
    cout << res << endl;
    return 0;
}