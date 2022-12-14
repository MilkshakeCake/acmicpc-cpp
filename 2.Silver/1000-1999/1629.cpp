// 곱셈 - BOJ #1629

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

int A, B, C;
ll sum = 0;

void dnc(int b) {
    if(b == 1) {
        sum += A % C;
        return;
    }

    
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ull A, B, C;
	cin >> A >> B >> C;

	int tmp = B;
	vector<int> vBinary;
	vector<ull> vVal;
	ull Result = 1;

	while (tmp != 0) {
		vBinary.push_back(tmp % 2);
		tmp /= 2;
	}

	for (int i = 0; i < sz(vBinary); i++) {
		if (i == 0) vVal.push_back(A % C);
        
		else vVal.push_back((vVal[i - 1] * vVal[i - 1]) % C);

		if (vBinary[i])	{
			Result = (Result * vVal[i]) % C;
		}
	}

	cout << Result;
}