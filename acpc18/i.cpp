#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX_N 100'000
typedef pair<int, int> ii;

ii c[MAX_N];
int h[MAX_N];
void sol()
{
	int n, k, t;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		c[i] = {t, i};
	}
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}

	sort(c, c + n);
	int s = 0;
	cout << c[k - 1].first << " ";
	if (c[k - 1].first != c[k].first)
	{

		for (int i = 0; i <= k - 1; i++)
		{
			s += h[c[i].second];
		}
		cout << s << endl;
	}
	else
	{
		int j = k;
		while (c[j + 1].first == c[k].first)
			j++;
		for (int i = 0; i <= j; i++)
		{
			v.push_back(h[c[i].second]);
		}
		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < k; i++)
		{
			s += v[i];
		}
		cout << s << endl;
	}
}

int main()
{
	sol();
	return 0;
}