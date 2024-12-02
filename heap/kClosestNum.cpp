#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k closest numbers to x in a sorted array.
 *
 * @param arr A sorted array of integers.
 * @param x The target value to find closest numbers to.
 * @param k The number of closest numbers to find.
 *
 * @returns A vector of k integers that are the closest to x in the array.
 *
 * Time complexity: O(n log k)
 * Space complexity: O(k)
 */
vector<int> kClosestx(vector<int> arr, int x, int k)
{
  priority_queue<pair<int, int>> pq;
  vector<int> ans;
  for (int i = 0; i < arr.size(); i++)
  {
    pq.push({abs(x - arr[i]), arr[i]});
    if (pq.size() > k)
    {
      pq.pop();
    }
  }

  while (pq.size() > 0)
  {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}

int main()
{
  vector<int> arr = {5, 6, 7, 8, 9};
  int x = 7;
  int k = 3;
  vector<int> ans = kClosestx(arr, x, k);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}