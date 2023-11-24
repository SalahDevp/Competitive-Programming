#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

#define MAX_N 100000
#define MAX_Q 100000
#define ui unsigned int

ui a[MAX_N];
ui x[MAX_Q];

void sol()
{
	ui n, q;
	cin >> n >> q;

	for (ui i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (ui i = 0; i < q; i++)
	{
		cin >> x[i];
	}

	for (ui i = 0; i < q; i++)
	{
		for (ui j = 0; j < n; j++)
		{
			if (a[j] % (ui)pow((ui)2, x[i]) == 0)
				a[j] += (ui)pow(2, x[i] - 1);
		}
	}

	for (ui i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		sol();
	return 0;
}