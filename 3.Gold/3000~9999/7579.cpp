// 앱 - BOJ #7579
// DP knapsack
// 재풀이 필요

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

int memory[101];
int cost[101];
int dp[101][10001];
int N,M;
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin>>memory[i];
    }
    for(int i=1;i<=N;i++){
        cin>>cost[i];
        sum+=cost[i];
    }
    
    
    for(int i=1;i<=N;i++){
        for(int c=0;c<=sum;c++){
            if(cost[i]>c)
                dp[i][c]=(dp[i-1][c]);
            else
                dp[i][c]=max(dp[i-1][c],dp[i-1][c-cost[i]]+memory[i]);
        }
    }

    for (int i = 0; i <= sum; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i << endl;
			break;
        }
	}
}