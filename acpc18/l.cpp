#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sol()
{
	int n, k, t;
	cin >> n >> k;
	int *v = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int max = 0, tm, mi;
	while (k--)
	{
		tm = max;
		for (int i = 0; i < n; i++)
		{
			if ((max | v[i]) > tm)
			{
				tm = max | v[i];
				mi = i;
			}
		}
		if (tm > max)
		{
			max = tm;
			cout << v[mi] << " ";
		}
		else
			k = 0;
	}
	cout << max << endl;
}

int main()
{
	sol();
	return 0;
}