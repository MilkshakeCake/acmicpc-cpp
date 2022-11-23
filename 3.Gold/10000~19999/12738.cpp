// 가장 긴 증가하는 부분 수열 3 - Baekjoon Online Judge #12738

#include <bits/stdc++.h>

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