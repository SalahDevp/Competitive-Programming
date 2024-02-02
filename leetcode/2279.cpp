// Problem: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int maximumBags(vector<int> &c, vector<int> &r, int a)
	{
		int n = c.size();
		int m;
		for (int i = 0; i < n; i++)
		{
			r[i] = c[i] - r[i];
		}
		sort(r.begin(), r.end());
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (r[i] > 0)
			{
				m = min(r[i], a);
				r[i] -= m;
				a -= m;
			}
			if (r[i] == 0)
				ans++;
		}
		return ans;
	}
};