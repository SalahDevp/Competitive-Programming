#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX_N 300
#define MAX_K 300

bitset<MAX_N> f[MAX_N];
double dp[2 * MAX_N * MAX_N][2];

void sol()
{
	int n, k;
	int b;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b;
			f[i][j] = b;
		}
	}
	double p;
	double s = 0.0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p = (double)(4 * (i + 1) * (n - i) * (j + 1) * (n - j)) / (double)pow(n * (n + 1), 2);
			dp[(i * n + j) * 2][0] = f[i][j] == 0 ? 1 : 0;
			dp[(i * n + j) * 2 + 1][0] = f[i][j] == 1 ? 1 : 0;
			for (int r = 1; r <= k; r++)
			{
				for (int s = 0; s < 2; s++)
				{
					dp[2 * (i * n + j) + s][r % 2] = dp[2 * (i * n + j) + 1 - s][(r + 1) % 2] * p + dp[2 * (i * n + j) + s][(r + 1) % 2] * (1 - p);
				}
				if (r == k)
					s += dp[2 * (i * n + j) + 1][r % 2];
			}
		}
	}
	cout << fixed << setprecision(5) << setfill('0') << s << endl;
}

int main()
{
	sol();
	return 0;
}