// 트리의 부모 찾기 - BOJ #11725

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

vt<int> tree[100001];
vt<int> parent(100001, 0);

void dfs(int k) {
    for(auto i : tree[k]) {
        if(!parent[i]) {
            parent[i] = k;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;


    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    parent[1] = 1;
    dfs(1);

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
}