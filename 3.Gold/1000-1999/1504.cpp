// 특정한 최단 경로 - Baekjoon Online Judge #1504

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

struct Node {
    ll w, idx;

    bool operator<(const Node &b) const {
        return w > b.w;
    }
};

int N, E;
vt<Node> graph[802];

ll dijkstra(int start, int end) {
    vt<ll> cache(N + 1, INT32_MAX);
    cache[start] = 0;

    priority_queue<Node> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        
        if (now.w > cache[now.idx]) continue;

        for (const auto &next : graph[now.idx]) {
            if (next.w + now.w < cache[next.idx]) {
                cache[next.idx] = next.w + now.w;
                pq.push({cache[next.idx], next.idx});
            }
        }
    }
    return cache[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> E;
    while(E--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    int v1, v2;
    cin >> v1 >> v2;

    ll v1thruv2 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    ll v2thruv1 = dijkstra(1, v2) + dijkstra(v1, v2) + dijkstra(v1, N);
    if(v1thruv2 >= INT32_MAX && v2thruv1 >= INT32_MAX) cout << "-1" << '\n';
    else cout << min(v1thruv2, v2thruv1);
}