// 상근이의 여행 - BOJ #9372

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
    
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;

        int a, b;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
        }

        cout << n-1 << '\n';
    }
}