#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

struct s {
  int c;
  int n;
};

class Solution {
public:
  int destroyTargets(vector<int> &nums, int space) {

    unordered_map<int, s> mp;
    int seedPtr = -1;

    for (int i = 0; i < nums.size(); i++) {
      int mod = nums[i] % space;
      auto it = mp.find(mod);
      if (it == mp.end()) {
        mp[mod].c = 1;
        mp[mod].n = nums[i];
      } else {
        it->second.c++;
        it->second.n = min(nums[i], it->second.n);
      }

      if ((seedPtr < 0) || (mp[mod].c > mp[seedPtr].c) ||
          (mp[mod].c == mp[seedPtr].c && mp[mod].n < mp[seedPtr].n))
        seedPtr = mod;
    }
    return mp[seedPtr].n;
  }
};
