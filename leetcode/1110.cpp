#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> ds(to_delete.begin(), to_delete.end());
    vector<TreeNode *> res;

    // postorder traversal
    stack<pair<TreeNode *, bool>> s;
    s.push({root, false});

    while (!s.empty()) {
      auto [p, v] = s.top();
      s.pop();
      if (v) {
        if (p->left && ds.find(p->left->val) != ds.end()) {
          if (p->left->left)
            res.push_back(p->left->left);
          if (p->left->right)
            res.push_back(p->left->right);
          p->left = nullptr;
        }
        if (p->right && ds.find(p->right->val) != ds.end()) {
          if (p->right->left)
            res.push_back(p->right->left);
          if (p->right->right)
            res.push_back(p->right->right);
          p->right = nullptr;
        }
        continue;
      }

      s.push({p, true});
      if (p->right)
        s.push({p->right, false});
      if (p->left)
        s.push({p->left, false});
    }

    if (ds.find(root->val) != ds.end()) {
      if (root->left)
        res.push_back(root->left);
      if (root->right)
        res.push_back(root->right);
    } else
      res.push_back(root);

    return res;
  }
};
