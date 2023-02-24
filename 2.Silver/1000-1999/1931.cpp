// 회의실 배정 - BOJ #1931

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

bool compare(pii v1, pii v2) {
    if(v1.second == v2.second) {
        return v1.first < v2.first;
    }
    return v1.second < v2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, begin, end;
    cin >> n;
    vt<pii> conf;
    for(int i = 0; i < n; i++) {
        int start, fin;
        cin >> start >> fin;
        conf.push_back(make_pair(start, fin));
    }

    sort(all(conf), compare);

    end = conf[0].sc;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        begin = conf[i].fr;
        if(end <= begin) {
            end = conf[i].sc;
            cnt++;
        }
    }
    
    cout << cnt;
}