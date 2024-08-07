#include <bits/stdc++.h>
using namespace std;
int main() {
    int k = 0;
    string str;
    cin >> k >> str;
    k %= str.size();
    for (int i = 0; i < k; i++) { // k次右移 每次右移一个字符
        char temp = str[str.size() - 1];
        for (int j = str.size() - 1; j > 0; j--) {
            str[j] = str[j - 1];
        }
        str[0] = temp;
    }
    cout << str;
    return 0;
}