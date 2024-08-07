#include <bits/stdc++.h>
using namespace std;
int main() {
    int k = 0;
    string str;
    cin >> k >> str;
    k %= str.size();
    for (int i = str.size() - k; i < str.size(); i++) {
        cout << str[i];
    }
    for (int i = 0; i < str.size() - k; i++) {
        cout << str[i];
    }
    return 0;
}