// 젓가락 게임 - 충남대학교 SW_IT Contest F
// BOJ #25642

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

int main() {    
    int a, b;
    cin >> a >> b;
    int round = 0;
    while(a < 6 && b < 6) {
        round++;
        round % 2 ? b += a : a += b;
    }

    if(round % 2) cout << "yt";
    else cout << "yj";
}