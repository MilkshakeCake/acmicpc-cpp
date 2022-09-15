// RGB거리 - Baekjoon Online Judge no.1149

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

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
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x : a)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int house;
    cin >> house;
    int costdp[1001][3] = {{0, 0, 0}};
    int cost[3];

    for(int i = 1; i <= house; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        costdp[i][0] = min(costdp[i-1][1], costdp[i-1][2]) + cost[0];
        costdp[i][1] = min(costdp[i-1][0], costdp[i-1][2]) + cost[1];
        costdp[i][2] = min(costdp[i-1][1], costdp[i-1][0]) + cost[2];
    }
    cout << min(min(costdp[house][0], costdp[house][1]), costdp[house][2]);
}