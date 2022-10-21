// 토마토 - Baekjoon Online Judge #7576

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

vt<vt<int>> box(1005, vt<int>(1005, -1));
vt<vt<vt<pii>>> dp;
vt<pii> nland;
vt<vt<int>> visited(1005, vt<int>(1005));
vt<pii> ripe;
queue<pii> que;
pii last = {0, 0};
int n, m;
int needripe = 0;

void init() {
    vt<vt<pii>> temp(1005, vt<pii>(0));
    for(int i = 0; i < 1005; i++) dp.push_back(temp);
}

void bfs() {
    if(ripe.empty()) return;
    for(int i = 0; i < sz(ripe); i++) {
        que.push(ripe[i]);
        visited[ripe[i].fr][ripe[i].sc] = 0;
        last = ripe[i];
    }

    while(!que.empty()) {
        pii v = que.front();
        que.pop();

        for(int i = 0; i < sz(dp[v.fr][v.sc]); i++) {
            pii temp = dp[v.fr][v.sc][i];
            if(!box[temp.fr][temp.sc] && !visited[temp.fr][temp.sc]) {
                que.push(temp);
                visited[temp.fr][temp.sc] = visited[v.fr][v.sc] +1;
                last = temp;
                needripe--;
            }
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    bool raw = false;

    init();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int temp;
            scanf("%d", &temp);
            box[i][j] = temp;
            if(temp != -1) {
                if(box[i][j -1] != -1) {
                    dp[i][j].push_back(make_pair(i, j -1)); 
                    dp[i][j -1].push_back(make_pair(i, j));
                }
                if(box[i -1][j] != -1) {
                    dp[i -1][j].push_back(make_pair(i, j));
                    dp[i][j].push_back(make_pair(i -1, j));
                }
            }

            if(temp == 0) {
                needripe++;
                raw = true;
                if(box[i][j -1] == -1 && box[i -1][j] == -1) {
                    nland.push_back(make_pair(i, j));
                }
            }

            else if(temp == 1) {
                ripe.push_back(make_pair(i, j));
            }
        }
    }

    if(!raw) {
        printf("0");
        return 0;
    }

    for(int i = 0; i < sz(nland); i++) {
        int x = nland[i].fr;
        int y = nland[i].sc;
        if(box[x +1][y] == -1 && box[x][y +1] == -1) {
            printf("-1");
            return 0;
        }
    }

    bfs();

    if(needripe == 0) {
        printf("%d", visited[last.fr][last.sc]);
    }
    
    else printf("-1");
}