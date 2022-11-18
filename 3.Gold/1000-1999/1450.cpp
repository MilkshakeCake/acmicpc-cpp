    // 냅색문제 - Baekjoon Online Judge #1450

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

    using namespace std;

    ll N, C, ans, weight[31];
    vector<ll> group1;
    vector<ll> group2;

    void func(int s, int e, vector<ll> &v, ll sum) {
        if(s > e) {
            v.push_back(sum);
            return;
        }
        else {
            func(s +1, e, v, sum);
            func(s +1, e, v, sum + weight[s]);
        }
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> N >> C;
        
        for(int i = 0; i < N; i++) {
            cin >> weight[i];
        }

        func(0, N/2, group1, 0);
        func(N/2 + 1, N-1, group2, 0);
        sort(all(group2));
        
        for(auto& i : group1) ans += upper_bound(all(group2), C - i) - group2.begin();
        
        cout << ans << endl;
    }