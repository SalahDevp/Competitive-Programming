#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
#define SPEED              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{
		queue<TreeNode *> q;
		vector<vector<int>> res;
		int size;
		bool inv = false;
		q.push(root);
		while (!q.empty())
		{
			size = q.size();
			res.push_back(vector<int>(size));
			for (int i = 0; i < size; i++)
			{
				if (q.front()->left != nullptr)
					q.push(q.front()->left);
				if (q.front()->right != nullptr)
					q.push(q.front()->right);
				if (inv)
					res[res.size() - 1][size - i - 1] = q.front()->val;
				else
					res[res.size() - 1][i] = q.front()->val;
				q.pop();
			}
			inv = !inv;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
