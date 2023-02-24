// 공유기 설치 - BOJ #2110

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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, c;
    cin >> n >> c;

    vt<int> house(n, 0);
    vt<int> distance(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(all(house));

    int low = 0;
    int high = house[n -1];
    int cnt;

    while(low <= high) {
        int mid = (low + high) / 2;
        int last = 0;
        cnt = 1;
        for(int i = 1; i < n; i++) {
            if(house[i] - house[last] >= mid) {
                cnt++;
                last = i;
            }
        }

        if(cnt >= c) low = mid +1;
        else high = mid -1;
    }

    cout << high;
}

// 최소 거리를 기준으로 이분탐색