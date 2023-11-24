#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

typedef long long ll;

void sol()
{
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll prvs = a[0], mxs = a[0];
	int prv = a[0];
	for (int i = 1; i < n; i++)
	{
		if ((prvs < 0) || ((abs(prv) % 2 + abs(a[i]) % 2) != 1))
			prvs = a[i];
		else
		{
			prvs += a[i];
		}
		prv = a[i];
		mxs = max(mxs, prvs);
	}
	cout << mxs << endl;
}

int main()
{
	int t;
	SPEED;
	cin >> t;
	while (t--)
		sol();
	return 0;
}