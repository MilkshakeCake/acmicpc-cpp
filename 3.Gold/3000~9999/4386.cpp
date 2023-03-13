// 별자리 만들기 - BOJ #4386

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

vt<pair<double, double>> cosmos;
vt<pair<double, int>> distances[100];
vt<bool> tracker;
double sum = 0;

double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

// void prim(int idx) {

// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    tracker.assign(n, false);
    double cosx, cosy;
    for(int i = 0; i < n; i++) {
        cin >> cosx >> cosy;
        cosmos.push_back({cosx, cosy});
    }

    for(int i = 0; i < n; i++) {
        for(int j = i +1; j < n; j++) {
            double dist = distance(cosmos[i], cosmos[j]);
            distances[i].push_back({dist, j});
            distances[j].push_back({dist, i});
        }
    }

    double sum = 0;

    priority_queue<pair<double, int>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {
        pair<double, int> now = pq.top();
        pq.pop();

        if(tracker[now.second]) continue;
        tracker[now.second] = true;
        sum -= now.first;

        for(auto next : distances[now.second]) {
            if(tracker[next.second]) continue;
            pq.push({-next.first, next.second});
        }
    }

    cout << sum;
}