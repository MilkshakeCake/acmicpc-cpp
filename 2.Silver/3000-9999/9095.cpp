// 1, 2, 3 더하기 - BOJ #9095

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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[11] = {0, 1, 2, 4};
    for(int i = 4; i < 11; i++) {
        num[i] = num[i -1] + num[i -2] + num[i -3];
    }
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << num[n] << '\n';
    }
}