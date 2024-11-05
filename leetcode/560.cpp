#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

// NOTE: using a map would be better :)
class Solution
{
private:
	int bs(vector<ii> &arr, int t, int i)
	{
		int l = 0, r = arr.size() - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (arr[m].first == t)
			{
				if (arr[m].second == i)
					return m;
				else if (arr[m].second < i)
				{
					l = m + 1;
				}
				else
					r = m - 1;
			}
			else if (arr[m].first < t)
				l = m + 1;
			else
				r = m - 1;
		}
		return l;
	}

public:
	int subarraySum(vector<int> &nums, int k)
	{
		vector<int> prSum;
		prSum.reserve(nums.size() + 1);
		prSum.push_back(0);
		for (auto n : nums)
		{
			prSum.push_back(n + prSum[prSum.size() - 1]);
		}

		vector<ii> sortedSum;
		sortedSum.reserve(prSum.size());

		for (int i = 0; i < prSum.size(); i++)
		{
			sortedSum.push_back(make_pair(prSum[i], i));
		}
		sort(sortedSum.begin(), sortedSum.end());

		int t, res = 0;
		for (int i = 1; i < prSum.size(); i++)
		{
			t = prSum[i] - k;
			int j = bs(sortedSum, t, i) - 1;
			while (j >= 0 && sortedSum[j].first == t)
			{
				res++;
				j--;
			}
		}

		return res;
	}
};

int main()
{
	Solution sol;
	vector<int> inp = {1, 4, -9, 2, 7, 3, -1, -1, 2};

	int k = 3;

	cout << sol.subarraySum(inp, k);
}
