// 마트료시카 합치기 - Baekjoon Online Judge #25631

#include <bits/stdc++.h>
#include <map>

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
    
    map<int, int> mat;
    int n;
    cin >> n;
    int temp;
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(mat[temp] != 0) {
            cnt = max(cnt, ++mat[temp]);
        }
        else mat[temp]++;
    }
    cout << cnt;
}