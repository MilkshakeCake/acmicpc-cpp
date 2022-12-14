// 가장 긴 증가하는 부분 수열 2 - BOJ #12015

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
    int n;
    scanf("%d", &n);
    vt<int> arr;
    F_OR1(n) {
        int input;
        scanf("%d", &input);
        if(arr.empty() || arr.back() < input) {
            arr.push_back(input);
        }
        else {
            *lower_bound(all(arr), input) = input;
        }
    }

    cout << sz(arr);
}