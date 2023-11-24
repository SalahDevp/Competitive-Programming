#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

void sol()
{
	int n;
	cin >> n;
	if (n % 3 != 0)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		sol();
	return 0;
}