// 패션왕 신해빈 - BOJ #9735

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
    
    map<string, int> cloth;
    vt<string> partname;
    string type, part;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> type >> part;
            cloth[part]++;
            if(cloth[part] == 1) partname.push_back(part);
        }

        int result = 1;

        for(auto &i : partname) {
            result *= (cloth[i] + 1);
        }
        cout << result -1 << '\n';
        partname.clear();
        cloth.clear();
    }
}