// 题目描述
// 给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
// 输入描述
// 第一行输入为整数数组 Array 的长度 n，接下来 n
// 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b
// （b > = a），直至文件结束。
//输出描述 输出每个指定区间内元素的总和。
#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 100005
int arr[MAX_LENGTH];
int calSum(int &start, int &end) {
    return arr[end] - (start == 0 ? 0 : arr[start - 1]);
}
int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += i == 0 ? 0 : arr[i - 1]; //计算累加和
    }
    int start = 0;
    int end = 0;
    while (~scanf("%d%d", &start, &end)) {
        int res = calSum(start, end);
        printf("%d\n", res);
    }
    return 0;
}