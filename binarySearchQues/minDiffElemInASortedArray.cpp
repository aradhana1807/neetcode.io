#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Finds the element in a sorted array that has the minimum difference with the target value.
 *
 * This function takes a sorted array of integers and a target value, and returns the element in the
 * array that has the minimum difference with the target value. If the target value is present in the
 * array, the function returns the target value itself. Otherwise, it returns the element that is
 * closest to the target value.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 *
 * @param nums A sorted array of integers.
 * @param target The target value to search for.
 *
 * @returns The element in the array that has the minimum difference with the target value.
 */

int minDiffElemInASortedArray(vector<int> &nums, int target)
{
  int start = 0, end = nums.size() - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (target == nums[mid])
    {
      return nums[mid];
    }

    else if (target < nums[mid])
      end = mid - 1;
    else
    {
      start = mid + 1;
    }
  }

  if ((abs(nums[start] - target) < (abs(nums[end] - target))))
  {
    return nums[start];
  }

  else
  {
    return nums[end];
  }
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 10, 11, 14, 15, 16};
  int target = 13;
  cout << minDiffElemInASortedArray(nums, target) << endl;
  return 0;
}