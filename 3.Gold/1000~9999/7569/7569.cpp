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

struct Coordinate {
    int x;
    int y;
    int z;

    Coordinate(int xc, int yc, int zc) : x(xc), y(yc), z(zc) {};
};

vt<vt<vt<Coordinate>>> dp;
vt<vt<vt<int>>> boxes;
vt<Coordinate> ripe;
int needripe = 0;

void init() {
    vt<vt<Coordinate>> temp(101, vt<Coordinate>(101));
    vt<vt<int>> tmp(101, vt<int>(101));
    for(int i = 0; i < 101; i++) {
        dp.push_back(temp);
        boxes.push_back(tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Coordinate Co(0, 0, 0);
    
    int m, n, h;
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                int temp;
                cin >> temp;
                boxes[i][j][k] = temp;
                if(temp == 1) {
                    Co.x = i;
                    Co.y = j;
                    Co.z = k;
                    ripe.push_back(Co);
                }
            }
        }
    }
}