#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &nums, int target)
{
  int start = 0, end = nums.size() - 1;
  int res = -1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (target == nums[mid])
    {
      res = mid;
      end = mid - 1;
    }
    else if (target < nums[mid])
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }

  return res;
}

int lastOccurence(vector<int> &nums, int target)
{
  int start = 0, end = nums.size() - 1;
  int res = -1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (target == nums[mid])
    {
      res = mid;
      start = mid + 1;
    }
    else if (target < nums[mid])
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }

  return res;
}

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    return {firstOccurence(nums, target), lastOccurence(nums, target)};
  }
};

int main()
{
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  Solution s;
  vector<int> res = s.searchRange(nums, target);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}