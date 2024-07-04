#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int res = INT_MAX;
  void comb(vector<int> &n, int moves, int r, int l) {
    if (!moves) {
      res = min(res, n[l] - n[r]);
      return;
    }
    comb(n, moves - 1, r + 1, l);
    comb(n, moves - 1, r, l - 1);
  }

public:
  int minDifference(vector<int> &nums) {
    if (nums.size() <= 4)
      return 0;
    sort(nums.begin(), nums.end());

    int i = 0, j = nums.size() - 1;
    comb(nums, 2, i + 1, j);
    comb(nums, 2, i, j - 1);
    return res;
  }
};
