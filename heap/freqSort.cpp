#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts the given array of integers based on their frequency in descending order.
 *
 * Uses a priority queue to keep track of the frequency of each element. The element with
 * the highest frequency is popped from the queue and added to the result array. The same
 * element is added to the result array as many times as its frequency.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(n)
 *
 * @param nums The given array of integers.
 *
 * @return The sorted array of integers based on their frequency in descending order.
 */
vector<int> freqSort(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)
  {
    freq[nums[i]]++;
  }

  priority_queue<pair<int, int>> maxh;
  for (auto i = freq.begin(); i != freq.end(); i++)
  {
    maxh.push({i->second, i->first});
  }

  vector<int> ans;
  while (maxh.size() > 0)
  {
    int freq = maxh.top().first;
    int num = maxh.top().second;
    for (int i = 1; i <= freq; i++)
    {
      ans.push_back(num);
    }
    maxh.pop();
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 1, 1, 3, 2, 2, 4};
  vector<int> ans = freqSort(nums);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}