// 문자열 탑 쌓기 - Baekjoon Online Judge #25643

#include <bits/stdc++.h>

using namespace std;

int n, m;

bool flagging(string under, string over) {
    string& und = under;
    string& ov = over;
    // set example m as 4
    for(int i = 1; i < m *2; i++) {
        // i = 1, 2, 3
        if(i < m) {
            if(und.substr(0, i) == ov.substr(m - i, m)) {
                return true;
            }
            else continue;
        }
        // i = 4
        else if (i == m) {
            if(und == ov) {
                return true;
            }
            else continue;
        }
        // i = 5, 6, 7
        else {
            if(und.substr(i - m, m) == ov.substr(0, m *2 - i)) {
                return true;
            }
            else continue;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    string under;
    string over;
    cin >> under;
    bool flag = true;

    for(int i = 1; i < n; i++) {
        cin >> over;
        if(flagging(under, over)) {
            under = over;
            continue;
        }
        else {
            flag = false;
            break;
        }
    }

    cout << flag;
}