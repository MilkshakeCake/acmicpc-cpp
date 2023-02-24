// 가장 긴 증가하는 부분 수열 3 - BOJ #12738

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define printall(i, a) for (auto &i : a) cout << i << ' '
#define printall(i, a) for (auto & i : a) cout << i << ' '

using namespace std;

int N;
vt<int> sequence;
vt<int> lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        sequence.push_back(temp);
        if (lis.size() == 0 || lis.back() < sequence[i]) lis.push_back(sequence[i]);
        else lis[lower_bound(all(lis), sequence[i]) - lis.begin()] = sequence[i];
    }
    cout << lis.size();
}