// Problem: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
/*Solution:
using greedy approach
- if current element is greater than prev element add the difference to total
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minNumberOperations(vector<int> &t)
	{
		int res = t[0];
		int n = t.size();
		for (int i = 1; i < n; i++)
		{
			if (t[i] > t[i - 1])
				res += t[i] - t[i - 1];
		}
		return res;
	}
};