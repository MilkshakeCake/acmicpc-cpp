// 숨바꼭질 2 - BOJ #12851

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

vector<bool> visited(100001, false);
int n, k, t;
int cnt = 0;

void minDis() {
    queue<pii> que;

    que.push({n, 0});
    visited[n] = true;

    while(!que.empty()) {
        int now = que.front().fr;
        int time = que.front().sc;
        que.pop();
        visited[now] = true;

        if(cnt && now == k && time == t) cnt++;
        if(!cnt && now == k) {
            t = time;
            cnt++;
        }

        for(int i : {now -1, now +1, now *2}) {
            if(i < 0 || i > 100000 || visited[i]) continue;
            que.push({i, time +1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    minDis();
    cout << t << '\n' << cnt;
}