#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
struct grp
{
	int s;
	int e;
};

unordered_map<string, int>
		mem;
int arr[100'000];

// int gcd(int a, int b)
// {
// 	if (a == 1 || b == 1)
// 		return 1;
// 	int mx = max(a, b);
// 	int mn = min(a, b);
// 	if (!mn)
// 		return mx;
// 	int res;
// 	if (mem.find(to_string(mx) + " " + to_string(mn)) == mem.end())
// 	{
// 		res = gcd(mn, mx % mn);
// 		mem[to_string(mx) + " " + to_string(mn)] = res;
// 	}
// 	else
// 		res = mem[to_string(mx) + " " + to_string(mn)];
// 	return res;
// }

void sol()
{
	int n, k, prv = -1;
	cin >> n >> k;
	int sd = 0;
	int st = 0, ed;
	int s = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (prv >= 0 && gcd(prv, arr[i]) == 1)
			sd++;
		if (arr[i] == 1)
			prv = arr[i];
	}

	for (int i = 1; i < n - 1 && k > 0; i++)
	{
		if ((arr[i - 1] != 1) && (arr[i + 1] != 1) && (gcd(arr[i - 1], arr[i]) == 1) && (gcd(arr[i + 1], arr[i]) == 1))
		{
			arr[i] = 0;
			k--;
			sd -= 2;
		}
	}
	for (int i = 0; i < n - 1 && k > 0; i++)
	{
		if (gcd(arr[i], arr[i + 1]) == 1 && (arr[i] != 1 || arr[i + 1] != 1))
		{
			if (arr[i] != 1)
				arr[i + 1] = 0;
			else
				arr[i] = 0;
			k--;
			sd--;
		}
	}
	for (int i = 0; i < n - 1 && k > 0; i++)
	{
		if (arr[i] == 0 && arr[i + 1] == 1)
		{
			arr[i + 1] = 0;
			k--;
			sd--;
		}
		else if (arr[i] == 1 && arr[i + 1] == 0)
		{
			arr[i] = 0;
			k--;
			sd--;
		}
		else if (arr[i] == 1 && arr[i + 1] == 1 && k >= 2)
		{
			arr[i + 1] = 0;
			arr[i] = 0;
			k -= 2;
			sd--;
		}
	}
	cout << sd << endl;
}

int main()
{
	int q;
	cin >> q;
	while (q--)
		sol();
	return 0;
}