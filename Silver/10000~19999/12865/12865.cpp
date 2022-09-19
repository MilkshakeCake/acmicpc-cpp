// "Project_Name" - Baekjoon Online Judge no."Project_Num"

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
    
    vt<int> dpv;
    vt<int> dpw;
    vt<pii> arr;

    int n, k;
    cin >> n >> k;
    int temp1, temp2;
    for(int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        arr.push_back(make_pair(temp1, temp2));
    }

    dpw[0] = arr[0].sc;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(dpw[j] + arr[i].sc <= k) {
                dpw[i] = dpw[j] + arr[i].sc;
            }
            else dpw[i] = arr[i].sc;
        }
    }
}