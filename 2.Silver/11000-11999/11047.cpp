// 동전 0 - BOJ #11047

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
    
    int n, k;
    cin >> n >> k;
    int arr[11] = {0};
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i = n; i > 0; i--) {
        if(k == 0) break;
        cnt += k / arr[i];
        k %= arr[i];
    }

    cout << cnt;
}