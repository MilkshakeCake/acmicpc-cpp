// 최단 경로 - Baekjoon Online Judge #1753

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <sstream>
#include <map>

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
    int w, idx;

    bool operator<(const Node &b) const {
        return w > b.w;
    }
};

int V, E, K;
vt<Node> graph[20002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E >> K;

    int u, v, w;
    while(E--) {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    vt<int> cache(V + 1, 1e9);
    cache[K] = 0;

    priority_queue<Node> pq;
    pq.push({0, K});

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

    for(int i = 1; i <= V; i++) {
        if(i == 1e9) cout << "INF" << '\n';
        else cout << cache[i] << '\n';
    }
}