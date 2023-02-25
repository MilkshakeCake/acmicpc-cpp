// 최솟값과 최댓값 - BOJ #2357

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

#define INF 1e9 +1

using namespace std;

vt<ll> arr(100007);
vt<ll> minTree;
vt<ll> maxTree;

ll init(int node, int start, int end, int mod) {
    if(start != end) { // not a leaf node
        int mid = (start + end) /2;
        if(mod) return minTree[node] = min(init(node *2, start, mid, mod), init(node *2 +1, mid +1, end, mod));
        else return maxTree[node] = max(init(node *2, start, mid, mod), init(node *2 +1, mid +1, end, mod));
    }

    // leaf node
    return (mod ? minTree[node] : maxTree[node]) = arr[start];
}

ll query(int node, int start, int end, int left, int right, int mod) {
    if(right < start || end < left) return (mod ? INF : 0);
    if(left <= start && end <= right) return (mod ? minTree[node] : maxTree[node]);

    int mid = (start + end) / 2;
    return mod ? min(query(node *2, start, mid, left, right, mod), query(node *2 +1, mid +1, end, left, right, mod)) : max(query(node *2, start, mid, left, right, mod), query(node *2 +1, mid +1, end, left, right, mod));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, a, b;
    cin >> n >> m;
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth +1);
    minTree.resize(treeSize);
    maxTree.resize(treeSize);

    for(int i = 0; i < n; i++) cin >> arr[i];

    init(1, 0, n -1, 0);
    init(1, 0, n -1, 1);

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << query(1, 0, n -1, a -1, b -1, 1) << ' ' << query(1, 0, n -1, a -1, b -1, 0) << '\n';
    }
}