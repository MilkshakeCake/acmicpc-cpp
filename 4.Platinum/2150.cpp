// Strongly Connected Component - BOJ #2150
// dfs

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
#define printall(i, a) \
    for (auto &i : a)  \
    cout << i << ' '
#define endl '\n'
#define INF INT32_MAX

using namespace std;

vt<Node> graph;
vt<Node> mirror;
priority_queue<int> stk;

struct Node {
    bool visit;
    int time;
    vt<int> idx;
};

void dfs(int p, int t, int root) {
    if(graph[p].visit) return;

    graph[p].visit = true;
    graph[p].time = t;

    for(auto &i : graph[p].idx) {
        if(graph[i].visit) continue;
        dfs(i, t + 1, root);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    graph.resize(v + 1);
    mirror.resize(v + 1);

    int start, end;
    for (int i = 0; i < e; i++)
    {
        cin >> start >> end;
        graph[start].idx.push_back(end);
        mirror[end].idx.push_back(start);
    }

    for(int i = 1; i <= v; i++) {
        
    }
}