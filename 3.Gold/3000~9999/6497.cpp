// Àü·Â³­ - BOJ #6497

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

vt<int> root(200000);

struct edge {
    int from;
    int to;
    int dis;
};

struct compare {
    
    bool operator()(const edge& e1, const edge& e2) {
        return e1.dis > e2.dis;
    }
};

int find(int idx) {
    if(root[idx] == idx) return idx;

    return find(root[idx]);
}

void uni(int a, int b) {
    int fa = find(a);
    int fb = find(b);

    root[fb] = fa;
}

priority_queue<edge, vt<edge>, compare> pq;
int m, n, from, to, dis;
ll sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        root[i] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> from >> to >> dis;
        pq.push({from, to, dis});
        sum += dis;
    }

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if(find(now.from) == find(now.to)) continue;
        uni(now.from, now.to);
        sum -= now.dis;
    }

    cin >> from >> to;

    cout << sum;
}