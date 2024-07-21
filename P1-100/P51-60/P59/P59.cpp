#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        //左上角点的坐标
        int i = 0;
        int j = 0;
        //右下角点的坐标
        int m = n - 1;
        int k = n - 1;
        //起始填写数值
        int start = 1;
        while (i <= m) {
            generateBorder(res, i++, j++, m--, k--, start);
        }
        return res;
    }

    void generateBorder(vector<vector<int>> &res, int i, int j, int m, int n,
                        int &start) {
        for (int col = j; col <= n; col++) {
            res[i][col] = start++;
        }
        for (int row = i + 1; row <= m; row++) {
            res[row][n] = start++;
        }
        for (int col = n - 1; col >= j; col--) {
            res[m][col] = start++;
        }
        for (int row = m - 1; row > i; row--) {
            res[row][j] = start++;
        }
    }
};

//打印矩阵
void printMatrix(vector<vector<int>> &res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(n);
    printMatrix(res);
    return 0;
}