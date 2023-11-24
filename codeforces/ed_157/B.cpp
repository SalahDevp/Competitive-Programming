#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int a[200];
void sol()
{
	int n;
	cin >> n;

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		s += abs(a[i] - a[i - 1]) + abs(a[i + n] - a[i - 1 + n]);
	}
	cout << s << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " " << a[i + n] << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		sol();
	return 0;
}