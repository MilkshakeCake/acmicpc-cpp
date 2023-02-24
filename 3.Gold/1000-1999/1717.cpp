// 집합의 표현 - BOJ #1717

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

int n, m;
vt<int> root;

int find(int node) {
    if(root[node] == node) return node;
    return root[node] = find(root[node]);
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    root[rb] = ra;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++) root.push_back(i);

    int flag, from, to;
    while(m--) {
        scanf("%d %d %d", &flag, &from, &to);
        if(!flag) uni(from, to);
        else cout << (find(from) == find(to) ? "YES" : "NO") << '\n';
    }
}