// Problem: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int maximumTastiness(vector<int> &price, int k)
	{

		auto check = [&](int x)
		{
			int c = 1;
			int prv = price.front();
			for (auto i : price)
			{
				if (i - prv >= x)
				{
					c++;
					prv = i;
				}
				if (c == k)
					return true;
			}
			return false;
		};
		sort(price.begin(), price.end());
		int r = (price.back() - price.front()) / (k - 1) + ((price.back() - price.front()) % (k - 1) == 0 ? 0 : 1);
		int l = 1;
		int m = (l + r) / 2;
		int mx = 0;
		while (l <= r)
		{
			if (check(m))
			{
				l = m + 1;
				mx = max(mx, m);
			}
			else
				r = m - 1;
			m = (l + r) / 2;
		}
		return mx;
	}
};