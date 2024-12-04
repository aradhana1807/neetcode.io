#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Prints the top k frequent numbers in a given array.
 *
 * @param[in] nums The given array of integers.
 * @param[in] k The value of k.
 *
 * @note Uses a min heap of size k to keep track of the k highest frequency
 * numbers seen so far. After going through the entire array, the top element of
 * the min heap is the kth highest frequency element.
 *
 * Time complexity: O(n log k)
 * Space complexity: O(k)
 */
vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> mp;

  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]]++;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
  vector<int> ans;

  for (auto i = mp.begin(); i != mp.end(); i++) {
    minH.push({i->second, i->first});
    if (minH.size() > k) {
      minH.pop();
    }
  }

  while (minH.size() != 0) {
    // cout << minH.top().second << " ";
    ans.push_back(minH.top().second);
    minH.pop();
  }

  return ans;
}

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  topKFrequent(nums, k);
  return 0;
}