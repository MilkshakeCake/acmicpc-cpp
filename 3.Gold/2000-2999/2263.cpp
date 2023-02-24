// 트리의 순회 - BOJ #2263
// Again By Myself

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

int n;
vt<int> inorder(100001, 0);
vt<int> inoIdx(100001, 0);
vt<int> postorder(100001, 0);

void split(int sIno, int eIno, int sPoo, int ePoo) {
    if(sIno > eIno || sPoo > ePoo) return;

    int rtIdx = inoIdx[postorder[ePoo]];
    int lsz = rtIdx - sIno;
    cout << inorder[rtIdx] << ' ';

    split(sIno, rtIdx, sPoo, sPoo + lsz -1);
    split(rtIdx +1, eIno, sPoo + lsz, ePoo -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> inorder[i];
        inoIdx[inorder[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }

    split(1, n, 1, n);
}