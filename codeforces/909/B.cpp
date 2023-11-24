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
	ll in;
	vector<ll> s(n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> in;

		s[i] = in + s[i - 1];
	}

	ll maxDif = 0;
	ll t;
	ll mx, mn;
	for (int k = 1; k <= n / 2 + 1; k++)
	{
		if (n % k != 0)
			continue;
		mx = 0;
		mn = INT_MAX;
		for (int j = k - 1; j <= n - 1; j += k)
		{
			t = s[j + 1] - s[j - k + 1];
			mx = max(t, mx);
			mn = min(t, mn);
		}
		maxDif = max(mx - mn, maxDif);
	}
	cout << maxDif << endl;
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