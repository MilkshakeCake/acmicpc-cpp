// K번째 수 - Baekjoon Online Judge #1300

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <sstream>
#include <map>

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

ll n, k;

int main() {
    cin >> n >> k;

    ll smol = 0;
    ll big = n * n;

    ll result = 1;

    while(smol <= big) {
        ll mid = (smol + big) /2;

        ll idx = 0;

        for(ll i = 1; i <= n; i++) {
            idx += min(n, mid / i);
        }

        if(idx >= k) {
            result = mid;
            big = mid -1;
        }
        else smol = mid +1;
    }

    cout << result;
}