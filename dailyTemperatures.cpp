#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++) {
      while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
        ans[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v = {30, 38, 30, 36, 35, 40, 28};
  vector<int> ans = s.dailyTemperatures(v);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}