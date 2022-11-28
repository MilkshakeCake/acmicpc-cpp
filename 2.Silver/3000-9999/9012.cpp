// 괄호 - BOJ #9012

#include <bits/stdc++.h>

using namespace std;

string vps(string str) {
    int cnt = 0;
    for(unsigned int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            cnt++;
        }
        else if(str[i] == ')') {
            if(cnt == 0) {
                return "NO";
            }
            cnt--;
        }
    }

    if(cnt == 0) {
        return "YES";
    }
    else {
        return "NO";
    }
}

int main() {
    int n;
    cin >> n;

    string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        cout << vps(temp) << '\n';
    }
}