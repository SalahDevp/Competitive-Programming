#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v = min(rowSum[i], colSum[j]);
        rowSum[i] -= v;
        colSum[j] -= v;
        res[i][j] = v;
      }
    }
    return res;
  }
};
