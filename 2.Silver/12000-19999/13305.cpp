// 주유소 - BOJ #13305

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
    road.push_back(road[n -1]);
    
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