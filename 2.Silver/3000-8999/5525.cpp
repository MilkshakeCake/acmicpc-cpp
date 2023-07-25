// IOIOI - BOJ #5525

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string s;
    cin >> n >> m >> s;

    vt<int> ns;

    bool flag = false;
    int cnt = 0;

    for(int i = 0; i < m -1; i++) {
        char now = s[i];
        char next = s[i +1];
        if(!flag) {
            if(now == 'O') continue;
            if(now == next) continue;
            flag = true;
            cnt++;
            continue;
        }

        if(now == next) {
            cnt /= 2;
            if(cnt >= n) ns.push_back(cnt);
            cnt = 0;
            flag = false;
            continue;
        }

        if(i == m - 2) {
            if(now == 'I') {
                cnt++;
                cnt /= 2;
                if(cnt >= n) ns.push_back(cnt);
                continue;
            }

            cnt /= 2;
            cnt++;
            if(cnt >= n) ns.push_back(cnt);
            continue;
        }

        cnt++;
    }

    cnt = 0;
    for(auto i : ns) {
        cnt += i - n + 1;
    }

    cout << cnt;
}