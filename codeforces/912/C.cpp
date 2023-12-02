#include <bits/stdc++.h>
using namespace std;

#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

typedef long long ll;
#define MAX_N 1'000'00
int a[MAX_N];
ll s[MAX_N + 1];

void sol()
{
	int n;
	cin >> n;
	s[n] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll res = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		s[i] = s[i + 1] + a[i];
		if ((s[i] > 0) && (i > 0))
		{
			res += s[i];
		}
	}
	res += s[0];

	cout << res << "\n";
}

int main()
{
	int t = 1;
	SPEED;
	cin >> t;
	while (t--)
		sol();
	return 0;
}