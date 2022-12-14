// 친구 네트워크 - BOJ #4195
// INCOMPLETE

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

vt<int> root;
vt<int> compSize(100001, 1);
map<string, int> idxOf;
int T, F, cnt(0);
string A, B;

int find(int node) {
    if(root[node] != node) root[node] = find(root[node]);
    return root[node];
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    root[max(rb, ra)] = min(rb, ra);
    
    compSize[b] += compSize[a];
    compSize[a] = compSize[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    while(T--) {
        for(int i = 0; i <= 100001; i++) root.push_back(i);
        cin >> F;

        while(F--) {
            cin >> A >> B;
            if(idxOf[A] == 0) {
                idxOf[A] = ++cnt;
                compSize[idxOf[A]] = 1;
            }

            if(idxOf[B] == 0) {
                idxOf[B] = ++cnt;
                compSize[idxOf[B]] = 1;
            }

            if(find(idxOf[A]) == find(idxOf[B])) {
                printf("%d\n", compSize[idxOf[A]]);
                continue;
            }

            uni(idxOf[A], idxOf[B]);
            printf("%d\n", compSize[idxOf[A]]);
        }

        cnt = 0;
        root.clear();
        compSize.assign(100001, 1);
        idxOf.clear();
    }
}