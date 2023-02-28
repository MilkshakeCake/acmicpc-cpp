// 친구 네트워크 - BOJ #4195
// INCOMPLETE

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

vt<int> root;
vt<int> compSize(200001, 0);
unordered_map<string, int> idxOf;

int find(int node) {
    if(root[node] != node) root[node] = find(root[node]);
    return root[node];
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if(ra == rb) return;
    
    root[max(rb, ra)] = min(rb, ra);
    
    compSize[a] += compSize[b];
    compSize[b] = compSize[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    int T, F, cnt(0);

    cin >> T;
    while(T--) {
        cin >> F;
        for(int i = 0; i <= 200001; i++) root.push_back(i);

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
                cout << compSize[idxOf[A]] << '\n';
                continue;
            }

            uni(idxOf[A], idxOf[B]);
            cout << compSize[idxOf[A]] << '\n';
        }

        cnt = 0;
        root.clear();
        idxOf.clear();
        compSize.assign(200001, 0);
    }
}