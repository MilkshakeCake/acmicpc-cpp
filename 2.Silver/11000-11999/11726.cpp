// 2*n 타일링 - BOJ #11726

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int fibo[1001] = {1, 1, 2, 0};
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        if(fibo[i]) continue;

        fibo[i] = fibo[i -1] + fibo[i -2];
        fibo[i] %= 10007;
    }

    cout << fibo[n];
}