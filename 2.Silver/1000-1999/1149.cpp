// RGB거리 - BOJ #1149
// Dynamic Programming

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
    
    int house;
    cin >> house;
    vt<vt<int> > costdp(1001, vt<int>(3, 0));
    int cost[3];

    for(int i = 1; i <= house; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        for(int j = 0; j < 3; j++) {
            costdp[i][j] = min(costdp[i -1][(j +1) %3], costdp[i -1][(j +2) %3]) + cost[j];
        }
    }
    cout << min(min(costdp[house][0], costdp[house][1]), costdp[house][2]);
}