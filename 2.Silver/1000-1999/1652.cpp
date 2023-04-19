// 누울 자리를 찾아라 - BOJ #1652

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<long, long>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

vt<vt<bool>> room(100, vt<bool>(100, true));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    char temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> temp;
            temp == '.' ? room[i][j] = true : room[i][j] = false;
        }
    }

    int cnt = 0;
    int len = 0;
    bool flag = false;

    // horizontal
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(room[i][j]) {
                if(!flag) {
                    flag = true;
                    len = 1;
                    continue;
                }

                if(len == 1) cnt++;
                len++;
                continue;
            }
            flag = false;
            len = 0;
        }
        len = 0;
    }

    cout << cnt << ' ';
    cnt = 0;

    // vertical
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            if(room[i][j]) {
                if(!flag) {
                    flag = true;
                    len = 1;
                    continue;
                }

                if(len == 1) cnt++;
                len++;
                continue;
            }
            flag = false;
            len = 0;
        }
        len = 0;
    }

    cout << cnt;
}