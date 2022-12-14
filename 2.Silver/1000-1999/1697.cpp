// 숨바꼭질 - BOJ #1697

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