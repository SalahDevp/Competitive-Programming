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
#define MAX_N 1'000

int m[MAX_N][MAX_N];
int a[MAX_N];

void sol()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> m[i][j];
	}
	if (n == 1)
	{
		cout << "YES" << endl;
		cout << 69 << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		a[i] = 2147483647;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			a[i] &= m[i][j];
			a[j] &= m[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i] | a[j]) != m[i][j])
			{
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
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