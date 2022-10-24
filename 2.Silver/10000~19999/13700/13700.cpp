// 완전 범죄 - Baekjoon Online Judge #13700

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

vt<int> mapo(100002, 0);
int n, s, d, f, b, k;

void bfs(int idx) {
    queue<int> que;
    que.push(idx);
    mapo[idx] = 1;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        if(v + f <= n && mapo[v + f] == 0) {
            que.push(v + f);
            mapo[v + f] = mapo[v] +1;
        }

        if(v - b > 0 && mapo[v - b] == 0) {
            que.push(v - b);
            mapo[v - b] = mapo[v] +1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s >> d >> f >> b >> k;

    int temp;
    for(int i = 0; i < k; i++) {
        cin >> temp;
        mapo[temp] = -1;
    }

    bfs(s);

    if(mapo[d] == 0) {
        cout << "BUG FOUND";
        return 0;
    }

    cout << mapo[d] -1;
}

// 1차원 그래프 너비 우선 탐색
//