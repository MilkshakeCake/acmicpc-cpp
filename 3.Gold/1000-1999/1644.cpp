// 소수의 연속합 - BOJ #1644

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

int n, sum, ans;
vector<int> primen(1, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    // if(n == 2) {
    //     cout << 1;
    //     return 0;
    // }

    vector<bool> isP(n +1, false);
    for (int i = 2; i * i <= n; i++) {
        if (!isP[i]) {
            for (int j = i * i; j <= n; j += i) {
                isP[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!isP[i]) primen.push_back(i + primen.back());
    }

    int start = 0;
    int finish = 0;
    int k = primen.size();
    while (true) {
        if (primen[finish] - primen[start] >= n) start++;
        else {
            if (finish == k) break;
            finish++;
        }

        if (primen[finish] - primen[start] == n) ans++;
    }

    cout << ans;
}