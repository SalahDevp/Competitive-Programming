#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

void sol()
{
	int x, y, k;
	cin >> x >> y >> k;

	if (x < y)
	{
		x = min(x + k, y);
		cout << y + y - x << endl;
		return;
	}
	if (y <= x)
	{
		cout << x << endl;
		return;
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