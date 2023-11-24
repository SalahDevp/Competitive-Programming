#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX_N 1000000

void sol()
{
	unordered_set<int> *vert[MAX_N] = {NULL};
	int n, m;
	int v1, v2;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		if (!vert[v1 - 1])
			vert[v1 - 1] = new unordered_set<int>;
		vert[v1 - 1]->insert(v2 - 1);
	}

	for (int i = 0; i < n; i++)

	{
		if (i == n - 1)
		{
			cout << "0";
			return;
		}
		if (!vert[i])
		{
			cout << "1 ";
			continue;
		}

		unordered_set<int>::iterator it = vert[i]->find(i + 1);
		if (it == vert[i]->end())
		{ // element doesnt exist.
			cout << "1 ";
		}
		else
			cout << "0 ";
	}
}

int main()
{
	sol();
	return 0;
}