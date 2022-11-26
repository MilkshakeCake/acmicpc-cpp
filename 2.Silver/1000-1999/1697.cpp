// 숨바꼭질 - Baekjoon Online Judge #1697

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vt<int> area(100001, -1);
    queue<int> que;
    que.push(n);
    area[n] = 0;
    while(area[k] == -1) {
        int now = que.front();
        que.pop();
        for(int i : {now -1, now +1, now *2}) {
            if(i < 0 || i > 100000) continue;
            if(area[i] != -1) continue;
            que.push(i);
            area[i] = area[now] +1;
        }
    }
    cout << area[k];
}