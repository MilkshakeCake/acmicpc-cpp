// 운동 - Baekjoon Online Judge #1956

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

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

#define INF INT32_MAX

using namespace std;

struct Node {
    ll w, idx;
    bool operator<(const Node &b) const {
        return w > b.w;
    }
};

int V, E;
ll candidate = INF;
vt<Node> graph[401];
vt<Node> backtrack[401];

ll dijkstra(int start, int end) {
    vt<ll> cache(V +1, INF);
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
    
    cin >> V >> E;
    int a, b, c;
    while(E--) {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        backtrack[b].push_back({c, a});
    }

    for(int i = 1; i <= V; i++) {
        for(auto &tail : backtrack[i]) {
            candidate = min(candidate, dijkstra(i, tail.idx) + tail.w);
        }
    }

    cout << (candidate != INF ? candidate : -1);
}