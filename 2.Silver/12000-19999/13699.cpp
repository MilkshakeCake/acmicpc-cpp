// 점화식 - BOJ #13699

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

ll t[36] = {1, 1, 0, };

ll recursive(int n) {
    if(n == 0 || n == 1) {
        t[n] = 1;
        return t[n];
    }

    if(t[n] != 0) return t[n];

    else {
        for(int i = 0; i < n; i++) {
            t[n] += recursive(i) * recursive(n -1 - i);
        }
        return t[n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cout << recursive(n);
}