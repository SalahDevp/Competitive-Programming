#include <bits/stdc++.h>
using namespace std;

struct s
{
	int t;
	int w;
	int i;
};

class Solution
{
public:
	vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
	{
		auto qCompare = [](s &a, s &b)
		{ return (a.t != b.t) ? a.t > b.t : ((a.w != b.w) ? a.w > b.w : a.i >= b.i); };
		auto compare = [](s &a, s &b)
		{ return (a.t != b.t) ? a.t < b.t : ((a.w != b.w) ? a.w < b.w : a.i <= b.i); };
		priority_queue<s, vector<s>, decltype(qCompare)>
				pq(qCompare);
		vector<s> sorted;
		vector<int> ans(tasks.size());

		for (int i = 0; i < servers.size(); i++)
		{
			sorted.push_back({0, servers[i], i});
		}
		sort(sorted.begin(), sorted.end(), compare);

		int i = 0;
		int j = 0;
		int time = 0;
		while (j < tasks.size())
		{
			while (j <= time && j < tasks.size() && (i < sorted.size() || !pq.empty() && pq.top().t <= time))
			{
				if (!pq.empty() && pq.top().t <= time)
				{
					s top = pq.top();
					ans[j] = top.i;
					pq.pop();
					top.t = tasks[j] + time;
					pq.push(top);
				}
				else if (i < sorted.size())
				{
					pq.push({time + tasks[j], sorted[i].w, sorted[i].i});
					ans[j] = sorted[i].i;
					i++;
				}
				j++;
			}
			if (i >= sorted.size() && pq.top().t > time)
			{
				time = pq.top().t;
			}
			else
				time++;
		}
		return ans;
	}
};

int main()
{
	Solution sol = Solution();
	vector<int> s = {3, 3, 2}, t = {1, 2, 3, 2, 1, 2};
	vector<int> ans = sol.assignTasks(s, t);
	for (auto a : ans)
		cout << a << " ";
}