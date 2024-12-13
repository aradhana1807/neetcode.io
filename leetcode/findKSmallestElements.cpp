#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> maxH;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
      maxH.push({abs(arr[i] - x), arr[i]});
      if (maxH.size() > k) {
        maxH.pop();
      }
    }

    while (maxH.size() > 0) {
      ans.push_back(maxH.top().second);
      maxH.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  vector<int> arr = {5, 6, 7, 8, 9};
  int k = 4;
  int x = 7;
  Solution s;
  vector<int> ans = s.findClosestElements(arr, k, x);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}