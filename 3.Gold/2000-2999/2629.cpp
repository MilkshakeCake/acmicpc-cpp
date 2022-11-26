// 양팔저울 - Baekjoon Online Judge #2629

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
    
    int n, wsum(0), temp;
    cin >> n;
    vt<int> weights;
    map<int, bool> wset;
    wset[0] = true;
    while(n--) {
        cin >> temp;
        wsum += temp;
        weights.push_back(temp);
    }

    for(auto &i : weights) {
        vt<int> temp;
        for(auto &j : wset) {
            temp.push_back(abs(j.first + i));
            temp.push_back(abs(j.first - i));
        }
        for(auto &j : temp) {
            wset[j] = true;
        }
    }

    cin >> n;
    vt<int> marbles;
    while(n--) {
        cin >> temp;
        marbles.push_back(temp);
    }

    for(auto &i : marbles) {
        if(i > wsum) {
            cout << "N ";
            continue;
        }

        if(wset[i]) cout << "Y ";
        else cout << "N ";
    }
}