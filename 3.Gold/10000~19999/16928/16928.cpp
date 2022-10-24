// 뱀과 사다리 게임 - Baekjoon Online Judge #16928

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <fstream>
#include <sstream>
#include <map>

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)

using namespace std;

vt<int> snl(102, 0);
vt<vt<int>> graph(102);

void bfs() {
    queue<int> que;
    
    que.push(1);
    snl[1] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        // for(auto& i : graph[v]) {
        //     if(snl[i] != 0) continue;

        //     if(sz(graph[v]) == 1) {
        //         que.push(i);
        //         snl[i] = snl[v];
        //         continue;
        //     }
            
        //     que.push(i);
        //     snl[i] = snl[v] + 1;
        // }
        for(int i = 0; i < sz(graph[v]); i++) {
            int temp = graph[v][i];
            if(snl[temp] != 0) continue;

            if(sz(graph[v]) == 1) {
                que.push(temp);
                snl[temp] = snl[v];
                continue;
            }

            que.push(temp);
            snl[i] = snl[v] +1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 7; j++) {
            if(i + j > 100) break;
            graph[i].push_back(i + j);
        }
    }

    int head, tail;
    for(int i = 0; i < n; i++) {
        cin >> head >> tail;
        graph[head].clear();
        graph[head].push_back(tail);
    }

    for(int i = 0; i < m; i++) {
        cin >> head >> tail;
        graph[head].clear();
        graph[head].push_back(tail);
    }

    bfs();

    for(int i = 1; i < 101; i++) {
        cout << i << ' ' << snl[i] << '\n';
    }
}

// #include <iostream>
// #include <queue>
// #include <cstring>
// using namespace std;

// // ladder or snake;
// int los[101];
// int d[101];

// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		int n1, n2;
// 		cin >> n1 >> n2;
// 		los[n1] = n2;
// 	}
// 	for (int i = 0; i < m; ++i)
// 	{
// 		int n1, n2;
// 		cin >> n1 >> n2;
// 		los[n1] = n2;
// 	}

// 	queue<int> q;
// 	memset(d, -1, sizeof(d));
// 	q.push(1);
// 	d[1] = 0;
// 	while (!q.empty())
// 	{
// 		int x = q.front();
// 		q.pop();
// 		for (int i = 1; i <= 6; ++i)
// 		{
// 			int nx = x + i;
// 			if (nx > 100) continue;

// 			// ladder or snake라면 이동해야 한다.
// 			if (los[nx] != 0) {
// 				nx = los[nx];
// 			}
// 			if (d[nx] == -1) {
// 				d[nx] = d[x] + 1;
// 				q.push(nx);
// 			}
// 		}
// 	}
// 	cout << d[100] << "\n";
// 	return 0;
// }