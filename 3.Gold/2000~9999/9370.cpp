// 미확인 도착지 - Baekjoon Online Judge #9370
// Dijkstra algorithm

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

    Node(ll weight, ll index) : w(weight), idx(index) {};

    bool operator<(const Node &b) const {
        return w > b.w;
    }
};

int n, m, t, s, g, h, a, b, d, temp;

ll dijkstra(int start, int end, vt<Node> graph[]) {
    vt<ll> cache(n +1, INT32_MAX);
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
    
    int T;
    cin >> T;
    while(T--) {
        vt<Node> graph[2001];
        vt<int> candis;
        int gh = 0;

        cin >> n >> m >> t >> s >> g >> h;

        while(m--) {
            cin >> a >> b >> d;
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
            if((a == g && b == h) || (a == h && b == g)) gh = d;
        }

        while(t--) {
            cin >> temp;
            ll gtoh = dijkstra(s, g, graph) + dijkstra(h, temp, graph) + gh;
            ll htog = dijkstra(s, h, graph) + dijkstra(g, temp, graph) + gh;
            if(dijkstra(s, temp, graph) == min(gtoh, htog)) candis.push_back(temp);
        }

        sort(all(candis));
        for(auto &i : candis) cout << i << ' ';
        cout << '\n';
    }
}