// 수열 - Baekjoon Online Judge no.2559

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    int maxn = -10000000;
    int temp = 0;
    vt<int> arr(1, 0);
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    for(int i = 1; i <= k; i++) {
        temp += arr[i];
    }
    maxn = max(maxn, temp);

    for(int i = 2; i < n - k + 2; i++) {
        temp -= arr[i -1];
        temp += arr[i + k -1];
        maxn = max(maxn, temp);
    }
    cout << maxn;
}