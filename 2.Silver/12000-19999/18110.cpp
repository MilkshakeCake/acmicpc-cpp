// solved.ac - BOJ #18110

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
    
    double n; cin >> n;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    vt<double> vec;
    deque<double> dq;
    double exclusion = n * 0.15;
    exclusion = round(exclusion);
    double temp;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    sort(all(vec));

    for(auto i : vec) dq.push_back(i);
    
    for(int i = 0; i < exclusion; i++) {
        dq.pop_back();
        dq.pop_front();
    }

    double avg = 0;
    for(auto i : dq) avg += i;

    avg /= (double)dq.size();
    avg = round(avg);
    cout << avg;
}