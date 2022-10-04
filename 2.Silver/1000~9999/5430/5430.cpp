// AC - Baekjoon Online Judge #5430

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
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string P;
        cin >> P;

        deque<int> dq;
        bool flag = false;
        bool error = false;

        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            char tmp;
            cin >> tmp;
            if((int)tmp > 47 && (int)tmp < 58) dq.push_back((int)tmp - 48);
        }

        for(int j = 0; j < sz(P); j++) {
            if(P[j] == 'R') {
                flag = !flag;
            }

            else {
                if(dq.empty()) {
                    error = true;
                    cout << "error" << '\n';
                    break;
                }

                if(flag) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
        
        if(error) break;

        cout << '[';
        if(!dq.empty()) {
            for(int j = 0; j < sz(dq) -1; j++) cout << dq[j] << ',';
            cout << dq.back();
        }
        cout << ']';
    }
}