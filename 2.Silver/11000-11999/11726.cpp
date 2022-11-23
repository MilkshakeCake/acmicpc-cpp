// 2*n 타일링 - Baekjoon Online Judge #11726

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

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