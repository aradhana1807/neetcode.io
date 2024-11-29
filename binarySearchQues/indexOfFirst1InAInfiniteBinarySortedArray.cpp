#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &nums, int target, int start, int end)
{
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

/**
 * @brief Finds the index of the first occurrence of 1 in an infinite binary sorted array.
 *
 * This function takes an infinite binary sorted array and a target value, and returns the
 * index of the first occurrence of the target value in the array. It uses a binary search
 * algorithm to efficiently locate the target value in the array.
 *
 * @param nums An infinite binary sorted array.
 * @param target The target value to search for.
 *
 * @returns The index of the first occurrence of the target value if found, otherwise returns -1.
 */
int indexOfFirst1InAInfiniteBinarySortedArray(vector<int> &nums, int target)
{
  int low = 0, high = 1;
  while (target > nums[high])
  {
    low = high;
    high = high * 2;
  }

  return firstOccurence(nums, target, low, high);
}

int main()
{
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
  vector<int> nums2 = {0, 1, 1, 1, 1, 1};
  int target = 1;
  cout << "Index: " << indexOfFirst1InAInfiniteBinarySortedArray(nums, target) << endl;
  cout << "Index: " << indexOfFirst1InAInfiniteBinarySortedArray(nums2, target) << endl;
  return 0;
}