// 버블 소트 - BOJ #1517

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
#define printall(i, a) \
    for (auto &i : a)  \
    cout << i << ' '
#define endl '\n'
#define INF INT32_MAX

using namespace std;

vector<pii> arr;
vector<int> tree;

void updateTree(int node, int begin, int end, int index)
{
    if (begin == end)
    {
        tree[node] = 1;
        return;
    }

    int mid = (begin + end) / 2;
    if (index <= mid)
        updateTree(node * 2, begin, mid, index);
    else
        updateTree(node * 2 + 1, mid + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int cntLess(int node, int begin, int end, int left, int right)
{
    if (left > end || right < begin)
        return 0;
    if (left <= begin && right >= end)
        return tree[node];
    int mid = (begin + end) / 2;

    int leftcnt = cntLess(node * 2, begin, mid, left, right);
    int rightcnt = cntLess(node * 2 + 1, mid + 1, end, left, right);
    return leftcnt + rightcnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, val;

    ll ans = 0;
    cin >> n;
    tree.resize(n * 4 + 1);
    arr.push_back({-INF, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        arr.push_back({val, i});
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++)
    {
        ans += (ll)cntLess(1, 1, n, arr[i].second + 1, n);
        updateTree(1, 1, n, arr[i].second);
    }

    cout << ans;
}
