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
#define MAX_N 100

int a[MAX_N];

void sol()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (k >= 2)
	{
		cout << "YES" << endl;
		return;
	}

	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
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