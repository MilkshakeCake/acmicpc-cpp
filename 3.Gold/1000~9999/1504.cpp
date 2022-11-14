// 특정한 최단 경로 - Baekjoon Online Judge #1504

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

int N, E;
vt<Node> graph[802];

int dijk(int start, int end) {
    vt<int> cache(N + 1, 1e9);
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
    }

    int v1, v2;
    cin >> v1 >> v2;

    int v1thruv2 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, N);
    int v2thruv1 = dijk(1, v2) + dijk(v1, v2) + dijk(v1, N);
    if(v1thruv2 > 1e9 && v2thruv1 > 1e9) cout << "-1" << '\n';
    else cout << min(v1thruv2, v2thruv1);
}