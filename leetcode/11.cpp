// Problem: https://leetcode.com/problems/container-with-most-water/description/
// Solution : greedy -> always increment the index of the smallest height
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int> &h)
	{
		int i = 0, j = h.size() - 1;
		int mx = 0;
		while (i != j)
		{
			mx = max(min(h[i], h[j]) * (j - i), mx);
			if (h[i] < h[j])
				i++;
			else
				j--;
		}
		return mx;
	}
};