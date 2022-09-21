// 쉬운 계단 수 - Baekjoon Online Judge no.10844
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>

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
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x : a)

#define mod 1000000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vt<int> col1(12, 1);
    int col2[12] = {0};

    col1[0] = 0;
    col1[1] = 0;
    col1[11] = 0;   

    while(--n) {
        for(int i = 1; i < 11; i++) {
            col2[i] = col1[i-1] % mod + col1[i+1] % mod;
            col2[i] %= mod;
        }
        for(int i = 1; i < 11; i++) {
            col1[i] = col2[i];
        }
        col1[0] = 0;
        col1[11] = 0;
    }
    int sum = 0;
    for(int i = 1; i < 11; i++) {
        sum += col1[i];
        sum %= mod;
    }
    cout << sum;
}