// 곱셈 - Baekjoon Online Judge #1629

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