// 회의실 배정 - BOJ #1931

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

bool compare(pii v1, pii v2) {
    if(v1.second == v2.second) {
        return v1.first < v2.first;
    }
    return v1.second < v2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, begin, end;
    cin >> n;
    vt<pii> conf;
    for(int i = 0; i < n; i++) {
        int start, fin;
        cin >> start >> fin;
        conf.push_back(make_pair(start, fin));
    }

    sort(all(conf), compare);

    end = conf[0].sc;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        begin = conf[i].fr;
        if(end <= begin) {
            end = conf[i].sc;
            cnt++;
        }
    }
    
    cout << cnt;
}