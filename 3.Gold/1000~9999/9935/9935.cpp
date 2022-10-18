// 문자열 폭발 - Baekjoon Online Judge #9935

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <sstream>
#include <map>

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