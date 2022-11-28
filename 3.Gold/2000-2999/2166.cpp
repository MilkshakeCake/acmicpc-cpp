// 다각형의 면적 - BOJ #2166

#include <bits/stdc++.h>
#include <iomanip>

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
    
    int n;
    double x, y;
    vt<pii> nodes;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        nodes.push_back({x, y});
    }

    double sum = 0;
    pair<double, double> v1;
    pair<double, double> v2;

    for(int i = 1; i < n -1; i++) {
        v1 = {nodes[i].fr - nodes[0].fr, nodes[i].sc - nodes[0].sc};
        v2 = {nodes[i +1].fr - nodes[0].fr, nodes[i +1].sc - nodes[0].sc};
        sum += (v1.fr * v2.sc - v1.sc * v2.fr) / 2;
    }

    sum = abs(sum);

    cout.precision(1);
    cout.setf(ios::showpoint);
    cout << fixed;
    cout << sum;
}