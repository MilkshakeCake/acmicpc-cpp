// 숨바꼭질 4 - Baekjoon Online Judge #13913

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

int n, k;
vt<int> grid(1e5 +1, -1);
vt<int> tracker(1e5 +1, 0);
vt<int> ans;

void minDis() {
    queue<int> que;

    que.push(n);
    grid[n] = 0;

    while(!que.empty()) {
        int now = que.front();
        que.pop();
        
        for(int i : {now -1, now +1, now *2}) {
            if(i < 0 || i > 100000) continue;
            if(grid[i] != -1) continue;
            que.push(i);
            grid[i] = grid[now] +1;
            tracker[i] = now;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    minDis();

    cout << grid[k] << '\n';
    
    int iter = k;
    stack<int> ans;
    ans.push(k);
    while(iter != n) {
        ans.push(tracker[iter]);
        iter = tracker[iter];
    }

    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}