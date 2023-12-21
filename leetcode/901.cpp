// problem: https://leetcode.com/problems/online-stock-span/description/
// Solution: next greatest element (stack method)
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

class StockSpanner
{
	stack<pair<int, int>> s;

public:
	StockSpanner()
	{
	}

	int next(int price)
	{
		int total = 1;

		while (!s.empty() && price >= s.top().ff)
		{
			total += s.top().ss;
			s.pop();
		}

		s.push(mp(price, total));
		return total;
	}
};