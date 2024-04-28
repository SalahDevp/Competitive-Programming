#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
	bool isPrime(int n)
	{
		if (n <= 1)
			return false;
		if (n == 2 || n == 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;
		for (int i = 6; i - 1 <= sqrt(n); i += 6)
		{
			if (n % (i - 1) == 0 || n % (i + 1) == 0)
				return false;
		}
		return true;
	}

public:
	int maximumPrimeDifference(vector<int> &nums)
	{
		int i = 0, j = nums.size() - 1;
		int p1 = 0, p2 = 0;
		while (i < j && (nums[i] != p1 || nums[j] != p2))
		{
			if (nums[i] != p1)
			{
				if (isPrime(nums[i]))
					p1 = nums[i];
				else
					i++;
			}
			if (nums[j] != p2)
			{
				if (isPrime(nums[j]))
					p2 = nums[j];
				else
					j--;
			}
		}
		return j - i;
	}
};

int main()
{
	vector<int> nm = {25, 9, 56, 31};
	Solution s = Solution();
	cout << s.maximumPrimeDifference(nm);
	return 0;
}