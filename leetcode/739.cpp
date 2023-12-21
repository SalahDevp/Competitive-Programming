// problem: https://leetcode.com/problems/daily-temperatures
// Solution: next greatest element (stack method)
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &t)
	{
		stack<pair<int, int>> s;
		int n = t.size();
		vector<int> ans(n, 0);

		s.push(mp(t[n - 1], n - 1));

		for (int i = n - 2; i >= 0; i--)
		{
			while (!s.empty() && s.top().ff <= t[i])
				s.pop();
			if (!s.empty())
			{
				ans[i] = s.top().ss - i;
			}
			s.push(mp(t[i], i));
		}
		return ans;
	}
};