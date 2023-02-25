// 만다라트 만들기 - BOJ #949-2
// 2023 ICPC Sinchon Winter Algorithm Camp Contest

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

string mandarat[9][9];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> mandarat[i][j];
        }
    }

    vt<pair<string, pii>> mid;
    for(int i = 3; i < 6; i++) {
        for(int j = 3; j < 6; j++) {
            mid.push_back({mandarat[i][j],{i, j}});
        }
    }
    sort(all(mid));

    // OUTPUT
    for(int i = 0; i < 9; i++) {
        pair<int, int> coor = mid[i].second;
        if(coor == make_pair(4, 4)) continue;
        printf("#%d. %s\n", (i > 4 ? i : i +1), mid[i].first.c_str());
        vt<string> detail;
        for(int x = (coor.first -3) *3; x <= (coor.first -3) *3 +2; x++) {
            for(int y = (coor.second -3) *3; y <= (coor.second -3) *3 +2; y++) {
                if(x == (coor.first -3) *3 +1 && y == (coor.second -3) *3 +1) continue;
                detail.push_back(mandarat[x][y]);
            }
        }

        sort(all(detail));
        for(int j = 0; j < 8; j++) {
            printf("#%d-%d. %s\n", (i > 4 ? i : i +1), j +1, detail[j].c_str());
        }
    }
}