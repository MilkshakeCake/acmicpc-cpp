// 문자열 폭발 - BOJ #9935

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string host, bomb;
    cin >> host >> bomb;
    deque<char> ret;

    int hlen = sz(host);
    int blen = sz(bomb);

    for(int i = 0; i < hlen; i++) {
        ret.push_back(host[i]);
        int bidx = blen;
        if(host[i] == bomb[--bidx] && sz(ret) >= sz(bomb)) { // bomb check loop start
            int idx = sz(ret) -1;
            bool tick = true;
            
            for(int j = 1; j < blen; j++) {
                if(ret[idx -j] != bomb[--bidx]) {
                    tick = false;
                    break;
                }
            }

            if(tick) for(int j = 0; j < blen; j++) ret.pop_back();
        }
    }

    if(!sz(ret)) {
        cout << "FRULA";
    }

    else {
        EACH(i, ret) cout << i;
    }
}