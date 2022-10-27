// Practice Techniques of C++

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

int main() {
    int n;
    int matrices[502];
    vt<int> pmul(502, 1);

    cin >> n;
    cin >> matrices[0] >> matrices[1];
    pmul[0] = matrices[0] * matrices[1];

    for(int i = 1; i < n; i++) {
        cin >> matrices[i] >> matrices[i +1];
        pmul[i] = pmul[i -1] * matrices[i +1];
    }

    for(int i = 0; i < n; i++) cout << pmul[i] << ' ';
    cout << '\n';
}