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
	map<string, int> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	double res;
	string key;
	ll c = 0;
	for (int i = 0; i < n; i++)
	{
		res = log2((double)a[i]) - (double)a[i];
		key = to_string((int)round(res * 10'000));
		if (m.find(key) == m.end())
			m[key] = 1;
		else
		{
			c += m[key];
			m[key]++;
		};
	}
	cout << c << endl;
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