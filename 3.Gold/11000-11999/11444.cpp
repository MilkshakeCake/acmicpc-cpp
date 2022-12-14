// 피보나치 수 6 - BOJ #11444

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

#define MOD 1000000007

using namespace std;

struct Matrix {
    ll n;
    vt<vt<ll> > board;

    Matrix(ll n) : n(n) {
        board.resize(n, vt<ll>(n, (ll)0));
    }

    Matrix operator*(const Matrix &m) const {
        Matrix output(n);
        for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                for(int c = 0; c < n; c++) {
                    output.board[a][b] += ((board[a][c] % MOD) * (m.board[c][b] % MOD)) % MOD;
                }
            }
        }
        return output;
    }
};

Matrix powerM(Matrix m, ll pow) {
    if(pow == 0) {
        Matrix output(m.n);
        for(int i = 0; i < m.n; i++) output.board[i][i] = 1;
        return output;
    }

    Matrix half = powerM(m, pow/2);
    return pow % 2 ? half * half * m : half * half;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;

    Matrix mat(2);

    mat.board = {{1, 1}, {1, 0}};

    mat = powerM(mat, n);

    cout << mat.board[1][0] % MOD;
}