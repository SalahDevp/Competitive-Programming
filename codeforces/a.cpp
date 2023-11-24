#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sol()
{
	int n;
	string s;
	cin >> n >> s;
	cout << endl;
	long long opt = 0;
	int j = n - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		while (s[j] != '0' && j >= 0)
			j--;
		if (j < 0)
		{
			cout << -1 << " ";
			continue;
		}
		opt += (long long)(i - j);
		cout << opt << " ";
		j--;
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