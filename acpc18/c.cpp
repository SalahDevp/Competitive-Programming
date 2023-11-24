#include <bits/stdc++.h>
#include <iostream>
using namespace std;

enum s
{
	SMALL,
	MEDIUM,
	LARGE
};

void sol()
{
	int c, p;
	cin >> c >> p;
	unordered_map<string, int[3]> cf;
	string t;
	int pr1, pr2, pr3;
	for (int i = 0; i < c; i++)
	{
		cin >> t >> pr1 >> pr2 >> pr3;
		cf[t][0] = pr1;
		cf[t][1] = pr2;
		cf[t][2] = pr3;
	}

	for (int i = 0; i < p; i++)
	{
		// easy i wont complete it
	}
}