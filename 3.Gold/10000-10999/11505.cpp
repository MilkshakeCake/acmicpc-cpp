// 구간 곱 구하기 - BOJ #11505

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

#define MAX 1000000

using namespace std;
int n, m, k;
ll arr[MAX];
ll makeSegTree(vector<ll> &segTree, int node, int start, int end) {
	if (start == end) return segTree[node] = arr[start];
	int mid = (start + end) / 2;

	return segTree[node] = (makeSegTree(segTree, node * 2, start, mid) * makeSegTree(segTree, node * 2 + 1, mid +1, end)) % 1000000007;
}

void updateSegTree(vector<ll> &segTree, int node, int start, int end, int idx, ll newn) {
	if (idx < start || idx > end) return;
	
	if(start == end) {
		segTree[node] = newn;
		return;
	}

	else {
		int mid = (start + end) /2;
		updateSegTree(segTree, node *2, start, mid, idx, newn);
		updateSegTree(segTree, node *2 +1, mid +1, end, idx, newn);
		segTree[node] = (segTree[node *2] * segTree[node *2 +1]) % 1000000007;
	}
}
ll productSegTree(vector<ll> &segTree, int node, int left, int right, int start, int end) {
	if (left > end || right < start) return 1;
	if (left <= start && right >= end) return segTree[node] % 1000000007;
	int mid = (start + end) / 2;
	return (productSegTree(segTree, node * 2, left, right, start, mid) * productSegTree(segTree, node * 2 + 1, left, right, mid+1, end)) % 1000000007;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    
	int treeDepth = ceil(log2(n));
	int treeSize = 1 << (treeDepth + 1);
	vector<ll> segTree(treeSize);
	
	makeSegTree(segTree, 1, 0, n -1);
	for (int i = 0; i < m + k; i++) {
		int order, bnum;
		ll cnum;
		cin >> order >> bnum >> cnum;
		if (order == 1) {
			//change
			updateSegTree(segTree, 1, 0, n -1, bnum -1, cnum);
			arr[bnum -1] = cnum;
		}
		else {
			//product
			cout << productSegTree(segTree, 1, bnum-1, cnum-1, 0, n -1) << endl;
		}
	}
	return 0;
}