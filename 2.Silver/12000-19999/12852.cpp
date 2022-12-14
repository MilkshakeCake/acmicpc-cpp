// 1로 만들기 2 - BOJ #12852

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int horizon[1000001] = {0};
    vt<int> path[1000001];
    path[1] = {1};

    queue<int> que;
    que.push(1);

    if(n == 1) {
        cout << 0 << '\n' << 1;
        return 0;
    }

    while(!que.empty() || horizon[n] == 0) {
        int now = que.front();
        que.pop();

        if(now +1 > n) continue;
        if(!horizon[now +1]) {
            horizon[now +1] = horizon[now] +1;
            path[now +1] = path[now];
            path[now +1].push_back(now +1);
            que.push(now +1);
        }
        if(now *2 > n) continue;
        if(!horizon[now *2]) {
            horizon[now *2] = horizon[now] +1;
            path[now *2] = path[now];
            path[now *2].push_back(now *2);
            que.push(now *2);
        }
        if(now *3 > n) continue;
        if(!horizon[now *3]) {
            horizon[now *3] = horizon[now] +1;
            path[now *3] = path[now];
            path[now *3].push_back(now *3);
            que.push(now *3);
        }
    }

    cout << horizon[n] << '\n';
    sort(all(path[n]), greater<int>());
    for(auto& i : path[n]) cout << i << ' ';
}