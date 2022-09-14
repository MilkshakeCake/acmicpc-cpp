// "Project_Name" - Baekjoon Online Judge no."Project_Num"

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
#define vtend(v) (v)[sz(v)-1]

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
    
    int n, temp;
    cin >> n;
    vt<int> origin;
    F_OR1(n) {
        cin >> temp;
        origin.push_back(temp);
    }

    vt<int> v;
    F_OR1(n) {
        if(i == 0) {
            v.push_back(origin[i]);
            continue;
        }
        v.push_back(origin[i] + vtend(v));
    }

    vt<pair<int, int> > pr;
    for(int i = 0; i < n; i++) {
        pr.push_back(make_pair(v[i], i));
    }
    sort(all(pr));

    int maxn = -1001;
    for(int i = pr[0].second; i < sz(v); i++) {
        if(v[i] > maxn) maxn = v[i];
    }
    
    if(vtend(pr).first < 0) {
        cout << vtend(pr).first;
        return 0;
    }

    cout << maxn - pr[0].first;
}