#include <iostream>
#include <vector>
using namespace std;

int lastOccurenceOfElem(vector<int> &nums, int target)
{
  int start = 0, end = nums.size() - 1;
  int res = -1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
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

int main()
{
  vector<int> arr = {4, 6, 7, 8, 8, 8, 9};
  int target = 8;
  cout << lastOccurenceOfElem(arr, target) << endl;
}