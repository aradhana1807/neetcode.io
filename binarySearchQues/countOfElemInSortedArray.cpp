#include <vector>
#include <iostream>
using namespace std;

int firstOccurenceOfElem(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;
  int res = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (target == arr[mid])
    {
      res = mid;
      end = mid - 1;
    }

    else if (target < arr[mid])
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

int countOfElemInSortedArray(vector<int> &nums, int target)
{
  return (lastOccurenceOfElem(nums, target) - firstOccurenceOfElem(nums, target) + 1);
}

int main()
{
  vector<int> arr = {4, 6, 7, 8, 8, 8, 9};
  int target = 8;
  cout << countOfElemInSortedArray(arr, target) << endl;
}
