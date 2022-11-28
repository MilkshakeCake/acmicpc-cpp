// 가장 긴 증가하는 부분 수열 5 - BOJ #14003

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, temp;
    vt<int> sequence;
    vt<int> lis;
    vt<int> tracker;
    stack<int> output;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        sequence.push_back(temp);

        if(!sz(lis) || lis.back() < sequence[i]) lis.push_back(sequence[i]);
        else lis[lower_bound(all(lis), sequence[i]) - lis.begin()] = sequence[i];

        tracker.push_back(lower_bound(all(lis), sequence[i]) - lis.begin());
    }

    int track = sz(lis) -1;
    for(int i = sz(tracker) -1; i >= 0; i--) {
        if(tracker[i] == track) {
            output.push(i);
            track--;
        }
    }

    cout << sz(lis) << '\n';

    while(!output.empty()) {
        cout << sequence[output.top()] << ' ';
        output.pop();
    }
}