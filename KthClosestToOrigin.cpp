#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    priority_queue<pair<int, pair<int, int>>> maxH;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
      maxH.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
      if (maxH.size() > k)
      {
        maxH.pop();
      }
    }

    vector<vector<int>> ans;

    while (maxH.size() > 0)
    {
      ans.push_back({maxH.top().second.first, maxH.top().second.second});
      maxH.pop();
    }

    return ans;
  }
};

int main()
{
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  int k = 2;
  Solution obj;
  vector<vector<int>> ans = obj.kClosest(points, k);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i][0] << " " << ans[i][1] << endl;
  }
  return 0;
}
