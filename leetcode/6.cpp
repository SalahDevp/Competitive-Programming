#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
  string convert(string s, int l) {
    if (l == 1)
      return s;
    string out = "";
    int i = 0, k = 0, minK = s.size();
    bool d = true;

    while (true) {
      int m = abs((d ? l - 1 : 0) - i);
      out += s[k];

      k += 2 * m;
      if (k < s.size()) {
        minK = min(minK, k);
        if (i != 0 && i != l - 1)
          d = !d;
      } else {
        i++;
        if (i >= minK)
          break;
        k = i;
        d = (i == l - 1) ? false : true;
      }
    }
    return out;
  }
};

int main() {
  Solution sol;
  cout << sol.convert("A", 1);
}
