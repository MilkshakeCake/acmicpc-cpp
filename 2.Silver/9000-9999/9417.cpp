// 최대 GCD - BOJ #9417

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

int gcd(int a, int b) {
    int c;
    while(b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, temp;
    int maxGcd = -1;
    string line, num;
    vector<int> v;

    cin >> t;
    cin.ignore();
    
    while (t--) {
        v.clear();
        maxGcd = -1;
        
        getline(cin, line);
        stringstream sstream(line);
        while (getline(sstream, num, ' ')) // 문자열 분리
            v.push_back(stoi(num));
        
        for (int i = 0; i < v.size() - 1; ++i) { // 완전탐색
            for (int j = i + 1; j < v.size(); ++j) {
                temp = gcd(v[i], v[j]);
                maxGcd = max(maxGcd, temp);
            }
        }
        cout << maxGcd << '\n';
    }
}