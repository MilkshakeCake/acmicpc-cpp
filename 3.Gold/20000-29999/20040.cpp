// 사이클 게임 - BOJ #20040

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define pll pair<long, long>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

vt<int> root(500001, 0);
vt<bool> isNew(500001, true);

int find(int node) {
    if(root[node] == node) return node;
    return find(root[node]);
}

bool uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return true;

    root[rb] = ra;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int a, b, result = 0;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        if(isNew[a]) {
            root[a] = a;
            isNew[a] = false;
        }
        if(isNew[b]) {
            root[b] = b;
            isNew[b] = false;
        }
        
        if(uni(a, b)) {
            result = i;
            break;
        }
    }

    cout << result;
}