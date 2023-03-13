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
vt<vt<double>> distances(101);
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

    cin >> cosx >> cosy;
    cosmos.push_back({cosx, cosy});
    int cnt = 0;

    for(int i = 1; i < n; i++) {
        cin >> cosx >> cosy;
        cosmos.push_back({cosx, cosy});
        for(int j = 0; j < i; j++) {
            distances[j].push_back(distance(cosmos[i], cosmos[sz(cosmos) -1]));
        }
    }

    
}