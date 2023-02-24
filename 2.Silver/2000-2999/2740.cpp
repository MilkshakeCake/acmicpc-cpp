// 행렬 곱셈 - BOJ #2740

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;

vt<vt<int> > matrixA;
vt<vt<int> > matrixB;

int N, M, K;

int matrix(int x, int y) {
    int result = 0;
    for(int i = 0; i < M; i++) {
        result += matrixA[x][i] * matrixB[i][y];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        vt<int> vTemp;
        int temp;
        for(int j = 0; j < M; j++) {
            cin >> temp;
            vTemp.push_back(temp);
        }
        matrixA.push_back(vTemp);
    }

    cin >> M >> K;
    for(int i = 0; i < M; i++) {
        vt<int> vTemp;
        int temp;
        for(int j = 0; j < K; j++) {
            cin >> temp;
            vTemp.push_back(temp);
        }
        matrixB.push_back(vTemp);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << matrix(i, j) << ' ';
        }
        cout << '\n';
    }
}