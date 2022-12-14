// K-Queen - BOJ #26006
// BOJ Contest 884 - 홍익대학교 PS 동아리 HI-ARC 2022

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool inC[3][3] = {false};
    
    int N, K, R, C;
    cin >> N >> K >> R >> C;
    if(R == 1) {
        inC[0][0] = true;
        inC[0][1] = true;
        inC[0][2] = true;
    }
    if(R == N) {
        inC[2][0] = true;
        inC[2][1] = true;
        inC[2][2] = true;
    }
    if(C == 1) {
        inC[0][0] = true;
        inC[1][0] = true;
        inC[2][0] = true;
    }
    if(C == N) {
        inC[0][2] = true;
        inC[1][2] = true;
        inC[2][2] = true;
    }

    int Ri, Ci;
    while(K--) {
        cin >> Ri >> Ci;
        for(int i = -1; i < 2; i++) {
            if(Ri == R + i) {
                inC[i +1][0] = true;
                inC[i +1][1] = true;
                inC[i +1][2] = true;
            }
            if(Ci == C + i) {
                inC[0][i +1] = true;
                inC[1][i +1] = true;
                inC[2][i +1] = true;
            }
            
            for(int j = -1; j < 2; j++) {
                if(abs(Ri - (R + i)) == abs(Ci - (C + j))) {
                    inC[i +1][j +1] = true;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(inC[i][j]) cnt++;
        }
    }

    if(cnt == 9) cout << "CHECKMATE";
    else if(cnt == 8 && !inC[1][1]) cout << "STALEMATE";
    else if(inC[1][1]) cout << "CHECK";
    else cout << "NONE";
}