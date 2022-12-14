// 최소 스패닝 트리 - BOJ #1197
// Kruskal MST

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

struct Edge {
    int w, from, to;

    bool operator<(const Edge &b) const { return w < b.w; }
};

vt<Edge> graph;
vt<int> root;
int V, E, cost(0);

int find(int a) {
    if(root[a] != a) root[a] = find(root[a]);
    return root[a];
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    root[max(ra, rb)] = min(ra, rb);
}

void MST() {
    sort(all(graph));
    for(int i = 0; i <= V; i++) root.push_back(i);

    for(auto &i : graph) {
        if(find(i.from) != find(i.to)) { 
            uni(i.from, i.to);
            cost += i.w;
        }
    }

    cout << cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E;
    int from, to, w;
    while(E--) {
        cin >> from >> to >> w;
        graph.push_back({w, from, to});
    }

    MST();
}