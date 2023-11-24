#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX_N 1000000

void sol()
{
	int n, k;
	int arr[MAX_N];
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		arr[i - 1] = i;

	int m = (int)floor((1 + sqrt(1 + 8 * k)) / 2);
	// invert last `m` items of array
	int i = n - m, j = n - 1;
	while (i < j)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	int tmpk = (m - 1) * m / 2;
	m++;
	i = n - m;
	j = n - 1;
	while (tmpk++ != k)
	{
		swap(arr[i], arr[j]);
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	sol();
	return 0;
}