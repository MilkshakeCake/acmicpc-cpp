// 나머지 합 - Baekjoon Online Judge no.10986

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
    
    int n, mod;
    cin >> n >> mod;
    vt<int> arr(mod, 0);

    int temp;
    unsigned ll int sum = 0;
    unsigned ll int result = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        sum %= mod;
        result += arr[sum % mod]++;
    }
    cout << result + arr[0];
}