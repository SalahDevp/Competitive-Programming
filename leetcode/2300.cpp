#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> successfulPairs(vector<int> &s, vector<int> &p, long long success)
	{
		int n = s.size(), m = p.size();
		vector<int> res(n);

		sort(p.begin(), p.end());
		long long target, tmp;
		for (int i = 0; i < n; i++)
		{
			tmp = (long long)s[i];
			target = success / tmp + ((success % tmp == 0) ? 0 : 1);
			if (target > (long long)p[p.size() - 1])
				res[i] = 0;
			else
			{
				auto it = lower_bound(p.begin(), p.end(), (int)target);
				res[i] = p.end() - it;
			}
		}

		return res;
	}
};

int main()
{
	Solution sol;
	vector<int> s = {5, 1, 3}, p = {1, 2, 3, 4, 5};
	sol.successfulPairs(s, p, 7);
}