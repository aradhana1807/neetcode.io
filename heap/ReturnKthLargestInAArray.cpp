#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void findKthLargest(vector<int> &nums, int k)
{
  priority_queue<int, vector<int>, greater<int>> minh;
  int i;
  for (i = 0; i < nums.size(); i++)
  {
    minh.push(nums[i]);
    if (minh.size() > k)
    {
      minh.pop();
    }
  }

  while (minh.size() != 0)
  {
    cout << minh.top() << " ";
    minh.pop();
  }
}

int main()
{
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  findKthLargest(nums, k);
}