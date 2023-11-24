#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;

void sol()
{
	int r, a, b;
	cin >> r >> a >> b;
	int i = 0;
	double s = 0.0;

	while (r)
	{
		s += (double)pow(r, 2);
		i = (i + 1) % 2;
		if (i == 1)
			r = r * a;
		else
			r = r / b;
	}
	cout << setprecision(10) << s * M_PI << endl;
}

int main()
{
	int t;
	cin >> t;
	int i = 1;
	while (t--)
	{
		cout << "Case #" << i++ << ": ";
		sol();
	}
	return 0;
}