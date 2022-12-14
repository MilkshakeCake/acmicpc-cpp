// 완전 범죄 - BOJ #13700

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

vt<int> mapo(100002, 0);
int n, s, d, f, b, k;

void bfs(int idx) {
    queue<int> que;
    que.push(idx);
    mapo[idx] = 1;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        if(v + f <= n && mapo[v + f] == 0) {
            que.push(v + f);
            mapo[v + f] = mapo[v] +1;
        }

        if(v - b > 0 && mapo[v - b] == 0) {
            que.push(v - b);
            mapo[v - b] = mapo[v] +1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s >> d >> f >> b >> k;

    int temp;
    for(int i = 0; i < k; i++) {
        cin >> temp;
        mapo[temp] = -1;
    }

    bfs(s);

    if(mapo[d] == 0) {
        cout << "BUG FOUND";
        return 0;
    }

    cout << mapo[d] -1;
}

// 1차원 그래프 너비 우선 탐색
//