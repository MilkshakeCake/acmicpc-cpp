// 최소비용 구하기 2 - Baekjoon Online Judge #11779

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
vt<Node> graph[1001];
vt<int> route[1001];

ll dijkstra(int start, int end) {
    vt<ll> cache(N +1, INT32_MAX);
    cache[start] = 0;

    priority_queue<Node> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        
        if (now.w > cache[now.idx]) continue;

        for (const auto &next : graph[now.idx]) {
            if (next.w + now.w < cache[next.idx]) {
                route[next.idx] = route[now.idx];
                route[next.idx].push_back(next.idx);
                
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
    int s, e, c;
    while(E--) {
        cin >> s >> e >> c;
        graph[s].push_back({c, e});
    }
    cin >> s >> e;

    cout << dijkstra(s, e) << '\n';
    cout << sz(route[e]) << '\n';
    for(auto &i : route[e]) cout << i << ' ';
}