// 전깃줄 2 - BOJ #2565
// LIS(Longest Incremental Subsequence)

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

    vt<int> LIS(1, line[1].to);
    vt<int> LISIdx(1, 0);
    vt<int> tracker(0);

    for(int i = 2; i <= k; i++) {
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

    cout << k - sz(LIS) << '\n';
    for(auto i : line) cout << i.from << ' ';
    cout << '\n';
    printall(i, LISIdx);
    cout << '\n';

    int now = sz(LIS) -1;
    for(int i = sz(LISIdx) -1; i > 0; i--) {
        if(now == LISIdx[i]) now--;
        else tracker.push_back(line[i].from);
    }

    sort(all(tracker));
    printall(i, tracker);
}