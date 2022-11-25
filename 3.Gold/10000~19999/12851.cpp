// 숨바꼭질 2 - Baekjoon Online Judge #12851

#include <bits/stdc++.h>

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

vector<int> grid(100001, -1);
int n, k;

void minDis() {
    queue<int> que;

    que.push(n);
    grid[n] = 0;

    while(!que.empty()) {
        int now = que.front();
        que.pop();
        
        if(now -1 < 0) continue;
        if(grid[now -1] == -1) {
            grid[now -1] = grid[now] +1;
            que.push(now -1);
        }

        if(now +1 > 1e5) continue;
        if(grid[now +1] == -1) {
            grid[now +1] = grid[now] +1;
            que.push(now +1);
        }

        if(now *2 > 1e5) continue;
        if(grid[now *2] == -1) {
            grid[now *2] = grid[now] +1;
            que.push(now *2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    minDis();
    cout << grid[k];
}