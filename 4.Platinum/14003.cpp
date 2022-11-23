// 가장 긴 증가하는 부분 수열 5 - Baekjoon Online Judge #14003

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
#define printall(i, a) for (auto &i : a) cout << i << ' '

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, temp;
    vt<int> sequence;
    vt<int> lis;
    stack<int> output;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        sequence.push_back(temp);
    }

    for(int i = 0; i < N; i++) {
        
    }
}