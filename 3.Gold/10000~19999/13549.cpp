// 숨바꼭질 3 - Baekjoon Online Judge #13549

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

using namespace std;

struct Node {
    ll w, idx;

    bool operator<(const Node &b) const {
        return w > b.w;
    }
};

int N, K;
vt<Node> graph[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    graph[0].push_back({1, 1});
    graph[100000].push_back({1, 99999});

    for(int i = 1; i <= 50000; i++) {
        graph[i].push_back({0, i *2}); graph[i].push_back({1, i -1}); graph[i].push_back({1, i +1});
    }

    for(int i = 50001; i < 100000; i++) {
        graph[i].push_back({1, i -1}); graph[i].push_back({1, i +1});
    }

    vt<int> cache(100001, INT32_MAX);
    cache[N] = 0;

    priority_queue<Node> pq;
    pq.push({0, N});

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        
        if (now.w > cache[now.idx]) continue;
        if(cache[K] < INT32_MAX) break;

        for (const Node &next : graph[now.idx]) {
            if (next.w + now.w < cache[next.idx]) {
                cache[next.idx] = next.w + now.w;
                pq.push({cache[next.idx], next.idx});
            }
        }
    }

    cout << cache[K];
    return 0;
}