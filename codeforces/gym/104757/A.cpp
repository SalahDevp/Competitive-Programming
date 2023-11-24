#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

int a[1'000'000];
int mn[1'000'000];
int mx[1'000'000];

void sol()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int x = 0, l = 1'000'000;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x)
			x = a[i];
		if (a[n - 1 - i] < l)
			l = a[n - 1 - i];
		mx[i] = x;
		mn[n - 1 - i] = l;
	}

	int m = 0;
	vector<int> out;
	for (int i = 0; i < n; i++)
	{
		if (mx[i] == mn[i])

		{
			m++;
			if (out.size() < 100)
				out.push_back(mx[i]);
		}
	}
	cout << m << " ";
	for (int i = 0; i < out.size(); i++)
		cout << out[i] << " ";
}

int main()
{
	SPEED
	sol();
	cout << endl;
	return 0;
}
