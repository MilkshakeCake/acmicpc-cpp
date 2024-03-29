// 구간 합 구하기 - BOJ #2042

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

#define MAX 1000000

using namespace std;
int n, m, k;
//1<=n<=1000000
//1<=m,k<=10000
ll arr[MAX];
ll makeSegmentTree(vector<ll> &segmentTree, int node, int start, int end) {
	if (start == end) {
		return segmentTree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	return segmentTree[node] = makeSegmentTree(segmentTree, node * 2, start, mid) + makeSegmentTree(segmentTree, node * 2 + 1, mid+1, end);
	
}

void updateSegmentTree(vector<ll> &segmentTree, int node, int start, int end,int idx, ll diff) {
	if (idx<start || idx > end) return;
	segmentTree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		updateSegmentTree(segmentTree, node * 2, start, mid, idx, diff);
		updateSegmentTree(segmentTree, node * 2 + 1, mid + 1, end, idx, diff);
	}
}
ll sumSegmentTree(vector<ll> &segmentTree, int node, int left, int right, int start, int end) {
	if (left>end || right<start) return 0;
	if (left <= start && right >= end) return segmentTree[node];
	int mid = (start + end) / 2;
	return sumSegmentTree(segmentTree, node * 2, left, right, start, mid) + sumSegmentTree(segmentTree, node * 2 + 1, left, right, mid+1, end);
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
	vector<ll> segmentTree(treeSize);
	
	makeSegmentTree(segmentTree,1,0,n-1);
	for (int i = 0; i < m + k; i++) {
		int order, left;
		ll right;
		cin >> order>> left >> right;
		if (order == 1) {
			//change
			updateSegmentTree(segmentTree, 1, 0, n - 1, left - 1, right-arr[left - 1]);
			arr[left - 1] = right;
		}
		else {
			//sum
			cout << sumSegmentTree(segmentTree, 1, left-1, right-1, 0, n - 1)<<'\n';
		}
	}
	return 0;
}