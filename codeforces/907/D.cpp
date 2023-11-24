#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, int> pll;

pll arr[] = {
		{4, 2},
		{8, 1},
		{9, 2},
		{729, 3},
		{50625, 4},
		{4084101, 5},
		{4194304, 4},
		{5153632, 5},
		{481890304, 6},
		{536870912, 5},
		{594823321, 6},
		{64339296875, 7},
		{68719476736, 6},
		{78364164096, 7},
		{11688200277601, 8},
		{1953125000000000, 9},
		{2251799813685248, 8},
		{2334165173090451, 9},
		{430804206899405824, 10}};

int bs(ll val)
{
	int l = 0, r = 18, i;
	while (l <= r)
	{
		i = (l + r) / 2;
		if (arr[i].first < val)
			l = i + 1;
		else if (arr[i].first > val)
			r = i - 1;
		else
			return i;
	}
	return r;
}

void sol()
{
	ll l, r;
	cin >> l >> r;
	int s = bs(l), e = bs(r);
	ll sm = 0;
	const ll MOD = 1'000'000'007;

	for (int i = s; i < e; i++)
	{
		sm = (sm + ((arr[i + 1].first - l) % MOD) * arr[i].second) % MOD;
		l = arr[i + 1].first;
	}
	sm = (sm + ((r - l + 1) % MOD) * arr[e].second) % MOD;
	cout << sm << endl;
}

int main()
{
	int q;
	cin >> q;
	while (q--)
		sol();
	return 0;
}

/*
x=4:  z=2
x=8:  z=1
x=9:  z=2
x=729:  z=3
x=50625:  z=4
x=4084101:  z=5
x=4194304:  z=4
x=5153633:  z=5
x=481890304:  z=6
x=536870912:  z=5
x=594823321:  z=6
*/