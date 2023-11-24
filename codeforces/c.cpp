#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct
{
	int l;
	int r;
} sg;

void sol()
{
	int *a;
	sg *s;
	int n, m;
	int maxI = 0;
	cin >> n >> m;
	a = new int[m];
	s = new sg[n];

	for (int i = 0; i < n; i++)
	{
		cin >> s[i].l >> s[i].r;
	}

	for (int i = 0; i < m; i++)
	{
		a[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = s[i].l - 1; j <= s[i].r - 1; j++)
		{
			if (a[maxI] < ++a[j])
				maxI = j;
		}
	}

	int first = 0, last = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxI >= s[i].l - 1 && maxI <= s[i].r - 1)
		{
			if (s[i].l - 1 == 0)
				first++;
			if (s[i].r - 1 == m - 1)
				last++;
		}
	}
	cout << a[maxI] - min(first, last) << endl;
	delete[] a;
	delete[] s;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		sol();

	return 0;
}