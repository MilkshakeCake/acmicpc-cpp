// 이진 검색 트리 - BOJ #5639

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

struct Node {
    int val, left, right;
};

vt<Node> tree;
int root, num, cnt(0);
bool flag;

void plant(int place, int idx) {
	if(tree[place].val > tree[idx].val) {
		if(tree[place].left == 0) tree[place].left = idx;
		else plant(tree[place].left, idx);
	}
	else {
		if(tree[place].right == 0) tree[place].right = idx;
		else plant(tree[place].right, idx);
	}
}

void postOrder(int now){
	if(tree[now].left != 0) postOrder(tree[now].left);
	if(tree[now].right != 0) postOrder(tree[now].right);
	cout << tree[now].val << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> num;
    tree.push_back({num, 0, 0});

    while(cin >> num) {
        cnt++;
        tree.push_back({num, 0, 0});
        plant(0, cnt);
    }

    postOrder(0);
}