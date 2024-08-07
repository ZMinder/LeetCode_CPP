#include <bits/stdc++.h>
using namespace std;
void transform(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') { //数字
            cout << "number";
        } else {
            cout << s[i];
        }
    }
}
int main() {
    string s;
    cin >> s;
    transform(s);
    return 0;
}