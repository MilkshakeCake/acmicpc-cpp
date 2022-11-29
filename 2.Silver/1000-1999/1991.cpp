// 트리 순회 - BOJ #1991
// 전위순회, 중위순회, 후위순회

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

struct Node {
    char left;
    char right;
};

int n;
vt<Node> tree(26);

void preorder(char root) {
    if(root == '.') return;

    cout << root;
    preorder(tree[root - 'A'].left);
    preorder(tree[root - 'A'].right);
}

void inorder(char root) {
    if(root == '.') return;

    inorder(tree[root - 'A'].left);
    cout << root;
    inorder(tree[root - 'A'].right);
}

void postorder(char root) {
    if(root == '.') return;

    postorder(tree[root - 'A'].left);
    postorder(tree[root - 'A'].right);
    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    char p, l, r;
    for(int i = 0; i < n; i++) {
        cin >> p >> l >> r;
        tree[p - 'A'] = {l, r};
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}