#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0)
#define MAX_N 200'000

int a[MAX_N - 1];
int b[MAX_N];
bitset<MAX_N> m;
void sol()
{
	int n;
	cin >> n;
	bool valid = true;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		m.reset();
		valid = true;
		b[0] = i;
		m[i] = 1;
		for (int j = 1; j < n; j++)
		{
			b[j] = a[j - 1] ^ b[j - 1];
			if (b[j] > n - 1 || m[b[j]])
			{
				valid = false;
				break;
			}
			m[b[j]] = 1;
		}
		if (valid)
			break;
	}
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

int main()
{
	SPEED;
	sol();
	return 0;
}