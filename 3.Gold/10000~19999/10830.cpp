// 행렬 제곱 - Baekjoon Online Judge #10830

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

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

vt<vt<vt<int> > > dp;
vt<vt<int> > matrix;

int n;
ll b;

vector<vector<int> > powerM(vt<vt<int> > A, vt<vt<int> > B) {
    vector<vector<int> > resultM;
    for(int a = 0; a < n; a++) {
        vector<int> temp;
        for(int b = 0; b < n; b++) {
            int result = 0;
            for(int i = 0; i < n; i++) {
                result += A[a][i] * B[i][b] %1000;
            }
            temp.push_back(result %1000);
        }
        resultM.push_back(temp);
    }

    return resultM;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> b;
    for(int i = 0; i < n; i++) {
        vt<int> vtemp;
        int tmp;
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            vtemp.push_back(tmp);
        }

        matrix.push_back(vtemp);
    }

    ll btmp = b;
    vt<bool> binary;
    while(btmp != 0) {
        binary.push_back(btmp %2);
        btmp /= 2;
    }

    dp.push_back(matrix);
    for(int i = 1; i < (int)binary.size(); i++) {
        dp.push_back(powerM(dp[i -1], dp[i -1]));
    }

    vt<vt<int> > resultM;
    for(int i = 0; i < n; i++) {
        vt<int> temp;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                temp.push_back(1);
                continue;
            }
            temp.push_back(0);
        }
        resultM.push_back(temp);
    }

    for(int i = 0; i < (int)binary.size(); i++) {
        if(binary[i]) {
            resultM = powerM(resultM, dp[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << resultM[i][j] << ' ';
        }
        cout << "\n";
    }
}