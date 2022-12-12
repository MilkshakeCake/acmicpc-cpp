// 여행 가자 - BOJ #1976

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

int N, M;
vt<int> root;

int find(int node) {
    if(root[node] != node) root[node] = find(root[node]);
    return root[node];
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    root[max(rb, ra)] = min(rb, ra);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i <= N; i++) root.push_back(i);

    bool temp;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> temp;
            if(!temp) continue;
            if(find(i) == find(j)) continue;
            uni(i, j);
        }
    }

    int now;
    bool flag = true;
    cin >> now;
    root[0] = root[now];
    for(int i = 1; i < M; i++) {
        cin >> now;
        if(find(now) != root[0]) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO");
}