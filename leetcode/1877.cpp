// Problem: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minPairSum(vector<int> &a)
	{
		int n = a.size();
		sort(a.begin(), a.end());
		int m = 0;
		for (int i = 0; i < n / 2; i++)
		{
			m = max(m, a[i] + a[n - i - 1]);
		}
		return m;
	}
};