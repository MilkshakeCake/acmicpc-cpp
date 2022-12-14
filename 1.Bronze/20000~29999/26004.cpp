// HI_ARC - BOJ #26004
// BOJ Contest 884 - 홍익대학교 PS 동아리 HI-ARC 2022

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
    
    int n; cin >> n;
    vt<int> letters(5, 0);
    for(int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        if(temp == 'H') {
            letters[0]++;
        }
        else if(temp == 'I') {
            letters[1]++;
        }
        else if(temp == 'A') {
            letters[2]++;
        }
        else if(temp == 'R') {
            letters[3]++;
        }
        else if(temp == 'C') {
            letters[4]++;
        }
    }

    sort(all(letters));
    cout << letters[0];
}