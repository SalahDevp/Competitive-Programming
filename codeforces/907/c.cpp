#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

#define MAX_N 200000

int h[MAX_N];

void sol()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];

	sort(h, h + n);
	int i = 0, j = n - 1;
	int x = 0, s = 0;
	int t;
	while (i < j)
	{
		if (x >= h[j])
		{
			x -= h[j];
			s++;
			j--;
		}
		t = min(h[j] - x, h[i]);
		s += t;
		x += t;
		h[i] -= t;
		if (i == 0)
			i++;
	}
	if (i == j)
	{

		s += (h[j] - x) / 2 + (h[j] - x) % 2 + 1;
	}
	cout << s << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		sol();
	return 0;
}