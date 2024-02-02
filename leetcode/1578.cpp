// Problem: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minCost(string c, vector<int> &t)
	{
		int n = t.size();
		int s = 0, l = 0, m = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			s += t[i];
			m = max(m, t[i]);
			l++;
			if ((i == n - 1) || (c[i + 1] != c[i]))
			{
				if (l > 1)
					ans += s - m;
				s = 0;
				l = 0;
				m = 0;
			}
		}
		return ans;
	}
};