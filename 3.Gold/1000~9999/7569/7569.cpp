// 토마토(3D) - Baekjoon Online Judge #7569

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
#include <tuple>

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

vt<vt<vt<int>>> boxes;
vt< vt<int> > ripe;
vt< vt<int> > moves = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
vt<int> last;
int m, n, h, needripe(0);

void init() {
    vt<vt<int>> box(102, vt<int>(102, -1));
    vt<vt<vt<int>>> step2;
    for(int i = 0; i < 102; i++) {
        boxes.push_back(box);
    }
}

void bfs() {
    queue<vt<int>> que;
    for(auto& i : ripe) {
        que.push({i[0], i[1], i[2]});
        last = i;
    }

    while(!que.empty()) {
        vt<int> v = que.front();
        que.pop();
        for(auto& i : moves) {
            int X = v[0] + i[0];
            int Y = v[1] + i[1];
            int Z = v[2] + i[2];

            if(X <= 0 || Y <= 0 || Z <= 0 || X > n || Y > m || Z > h) continue;
            if(boxes[X][Y][Z] != 0) continue;

            que.push({X, Y, Z});
            boxes[X][Y][Z] = boxes[v[0]][v[1]][v[2]] +1;
            last = {X, Y, Z};
            needripe--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int temp;

    scanf("%d %d %d", &m, &n, &h);
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                scanf("%d", &temp);
                boxes[j][k][i] = temp;
                if(temp == 1) ripe.push_back({j, k, i});
                else if(temp == 0) {
                    needripe++;
                }
            }
        }
    }

    if(needripe == 0) {
        printf("0");
        return 0;
    }

    bfs();

    if(needripe != 0) {
        printf("-1");
        return 0;
    }

    printf("%d", boxes[last[0]][last[1]][last[2]] -1);
}