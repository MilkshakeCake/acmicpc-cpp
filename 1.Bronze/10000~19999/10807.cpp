// 개수 세기 - BOJ #10807

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, v, sum(0);
    cin >> n;
    vector<int> ns(n, 0);
    for(auto& i : ns) cin >> i;
    cin >> v;
    for(auto i : ns) if(v == i) sum++;
    cout << sum;
}