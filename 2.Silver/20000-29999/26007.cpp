// Codepowers - BOJ #26007
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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vt<int> ratings(1, X);
    vt<int> count(1, 0);
    int temp;
    while(N--) {
        cin >> temp;
        ratings.push_back(temp + ratings.back());
        count.push_back(count.back() + (ratings.back() >= K ? 0 : 1));
    }

    while(M--) {
        int l, r;
        cin >> l >> r;
        cout << count[r -1] - count[l -1] << '\n';
    }
}