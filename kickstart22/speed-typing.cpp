#include <bits/stdc++.h>
using namespace std;

void sol()
{
	string s1, s2;
	getline(cin >> ws, s1);
	getline(cin, s2);
	int i, j, c = 0;
	for (i = 0, j = 0; i < s1.length(); i++, j++)
	{
		while (s2[j] != s1[i])
		{
			c++;
			j++;
			if (j >= s2.length())
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	c += s2.length() - j;
	cout << c << endl;
}

int main()
{
	int t;
	int s;
	cin >> t;
	while (t--)
	{
		sol();
	}
}