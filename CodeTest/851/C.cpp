// 홀짝 수열 - 충남대학교 SW_IT Contest C
// BOJ #25629

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
    int odd = 0;
    int even = 0;

    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        temp % 2 == 0 ? even++ : odd++;
    }

    if(odd - even == 0 || odd - even == 1) {
        cout << 1;
    }
    else cout << 0;
    return 0;
}