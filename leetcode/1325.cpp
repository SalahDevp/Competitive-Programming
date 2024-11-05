#include <bits/stdc++.h>
using namespace std;

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
private:
	TreeNode *deleteTarget(TreeNode *root, TreeNode *parent, int target, bool left)
	{
		if (root->left)
			deleteTarget(root->left, root, target, true);
		if (root->right)
			deleteTarget(root->right, root, target, false);

		if (!root->left && !root->right && root->val == target)
		{
			if (!parent)
				root = nullptr;
			else if (left)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		return root;
	}

public:
	TreeNode *removeLeafNodes(TreeNode *root, int target)
	{
		TreeNode *newRoot = nullptr;
		newRoot = deleteTarget(root, nullptr, target, false);
		return newRoot;
	}
};