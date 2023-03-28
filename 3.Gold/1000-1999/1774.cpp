// 우주신과의 교감 - BOJ #1774

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

struct edge {
    double len;
    int from;
    int to;
};

struct compare {
    bool operator()(const edge& e1, const edge& e2) {
        return e1.len > e2.len;
    }
};

vt<int> root(1000, 0);
vt<pair<double, double>> pantheon;
vt<vt<bool>> ready(1000, vt<bool>(1000));

int find(int node) {
    if(root[node] == node) return node;
    return find(root[node]);
}

void uni(int a, int b) {
    int fa = find(a);
    int fb = find(b);

    root[fb] = fa;
}

double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(2);
    
    int n, m, x, y;
    cin >> n >> m;

    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        root[i] = i;
        cin >> x >> y;
        pantheon.push_back({x, y});
    }

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        ready[x][y] = true;
        ready[y][x] = true;
    }

    priority_queue<edge, vt<edge>, compare> pq;

    for(int i = 0; i < n; i++) {
        for(int j = i +1; j < n; j++) {
            double dist = distance(pantheon[i], pantheon[j]);
            if(ready[i][j]) dist = 0;
            pq.push({dist, i, j});
        }
    }

    double sum = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        
        if(find(now.from) == find(now.to)) continue;
        sum += now.len;
        uni(now.from, now.to);
    }

    cout << sum;
}