#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 100
int row[MAX_LENGTH]; //每一行的累加和
int col[MAX_LENGTH]; //每一列的累加和
int n = 0;
int m = 0;
int num = 0; //用于读取数据
int main() {
    scanf("%d%d", &n, &m);
    fill(row, row + n, 0);
    fill(col, col + m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num);
            row[i] += num;
            col[j] += num;
        }
    }
    for (int i = 1; i < n; i++) {
        row[i] += row[i - 1];
    }
    for (int i = 1; i < m; i++) {
        col[i] += col[i - 1];
    }
    int min_dif = INT_MAX;
    for (int i = 0; i < n; i++) {
        min_dif = min(abs(row[i] - (row[n - 1] - row[i])), min_dif);
    }
    for (int i = 0; i < m; i++) {
        min_dif = min(abs(col[i] - (col[m - 1] - col[i])), min_dif);
    }
    printf("%d", min_dif);
    return 0;
}