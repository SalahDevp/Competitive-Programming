#include <bits/stdc++.h>
using namespace std;

#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

typedef long long ll;
#define MAX_N 1'000'00

ll a[MAX_N];
ll b[MAX_N];
int n, q;

void sol()
{
	ll k, s;
	cin >> k;
	ll m = 1LL << 62;
	int i = 63;
	memcpy(a, b, n * sizeof(ll));
	while (i--)
	{
		s = 0;
		for (int j = 0; j < n; j++)
		{
			if ((a[j] & ((m << 1) - 1)) < m)
				s += m - (a[j] & ((m << 1) - 1));
			if (s > k)
				break;
		}
		if (s <= k)
		{
			k -= s;
			for (int j = 0; j < n; j++)
				if ((a[j] & ((m << 1) - 1)) < m)
					a[j] += m - (a[j] & ((m << 1) - 1));
		}
		if (!k)
			break;
		m >>= 1;
	}
	ll r = a[0];
	for (int j = 1; j < n; j++)
		r &= a[j];
	cout << r << "\n";
}

int main()
{
	int t = 1;
	SPEED;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	while (q--)
	{
		sol();
	}

	return 0;
}