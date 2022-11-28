// 정수 삼각형 - BOJ #1932

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
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int upper[500] = {0};
    int lower[500] = {0};

    int n;
    cin >> n;
    cin >> upper[0];
    F_OR3(i, 1, n) {
        F_OR2(j, i + 1) {
            cin >> lower[j];
        }

        lower[0] += upper[0];

        F_OR3(j, 1, i) {
            lower[j] += max(upper[j], upper[j -1]);
        }
        
        lower[i] += upper[i-1];

        F_OR2(j, i + 1) {
            upper[j] = lower[j];
        }
    }
    sort(upper, upper + n, greater<int>());
    cout << upper[0];
}