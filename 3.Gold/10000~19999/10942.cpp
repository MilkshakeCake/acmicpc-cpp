// 팰린드롬? - Baekjoon Online Judge #10942

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

int numbers[2001] = {0};
vt<vt<bool>> dp(2001, vt<bool>(2001, -1));

bool pali(int s, int e) {
    if(dp[s][e] != -1) return true;
    if(s == e) return true;
    
    for(int i = s; i < e; i++) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;


    }
}