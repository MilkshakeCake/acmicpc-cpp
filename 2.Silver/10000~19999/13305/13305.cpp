// 주유소 - Baekjoon Online Judge no.13305

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

ll int price = 0;
int storage = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    vt<int> road(n, 0);
    vt<int> oil(n, 0);
    for(int i = 1; i < n; i++) {
        cin >> road[i];
    }
    road.push_back(road[n-1]);
    
    for(int i = 0; i < n; i++) {
        cin >> oil[i];
    }
    oil.push_back(0);

    for(int i = 0; i < n - 1; i++) {
        storage = min(storage, oil[i]);
        price += storage * road[i +1];
    }
    cout << price;
}