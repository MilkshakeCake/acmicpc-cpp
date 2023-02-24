// 전깃줄 2 - BOJ #2565
// LIS(Longest Incremental Subsequence)

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto i : a) cout << i << ' '

using namespace std;

struct Line {
    int from, to;

    bool operator<(const Line &b) const { return from < b.from; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;

    vt<Line> line(k +1, {0, 0});
    for(int i = 1; i <= k; i++) {
        cin >> line[i].from >> line[i].to;
    }

    sort(all(line));

    vt<int> LIS(1, 0);
    vt<int> LISIdx(1, 0);

    for(int i = 1; i <= k; i++) {
        int next = line[i].to;
        if(LIS.back() < next) {
            LIS.push_back(next);
            LISIdx.push_back(sz(LIS) -1);
            continue;
        }

        int nidx = lower_bound(all(LIS), next) - LIS.begin();
        LIS[nidx] = next;
        LISIdx.push_back(nidx);
    }

    // for(auto i : line) cout << i.to << ' ';
    // cout << '\n';
    // printall(i, LIS);
    // cout << '\n';
    // printall(i, LISIdx);
    // cout << '\n';

    int trace = sz(LIS) -1;
    cout << k - trace << '\n';
    
    LIS.clear();
    for(int i = k; i > 0; i--) {
        if(LISIdx[i] == trace) {
            LIS.push_back(line[i].to);
            trace--;
        }
    }
    sort(all(LIS));

    for(int i = 1; i <= k; i++) {
        if(LIS[trace] != line[i].to) cout << line[i].from << '\n';
        else trace++;
    }
}