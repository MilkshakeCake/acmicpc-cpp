// 타임머신 - Baekjoon Online Judge #11657
// Bellman-Ford Algorithm

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

#define INF INT32_MAX

using namespace std;

struct Edge {
    ll start, end, cost;
};

int N, M;
bool cycle = false;
vt<Edge> graph;
vt<ll> cache(501, INF);

void BellmanFord(int begin) {
    cache[begin] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < M; j++) {
            ll start = graph[j].start;
            ll end = graph[j].end;
            ll cost = graph[j].cost;
 
            if (cache[start] != INF && cache[end] > cache[start] + cost) cache[end] = cache[start] + cost;
        }
    }
 
    for (auto &i : graph) {
        int start = i.start;
        int end = i.end;
        int cost = i.cost;

        if (cache[start] == INF) continue;
        if (cache[end] > cache[start] + cost) {
            cycle = true;
            break;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a, b, c});
    }

    BellmanFord(1);

    if(cycle) {
        cout << -1;
        return 0;
    }

    else for(int i = 2; i <= N; i++) {
        cout << (cache[i] == INF ? -1 : cache[i]) << '\n';
    }
}