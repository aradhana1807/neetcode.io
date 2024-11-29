#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target, int low, int high)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

/**
 * @brief Finds the index of the target element in an infinite sorted array of integers.
 *
 * @param[in] nums The infinite sorted array of integers.
 * @param[in] target The target element to search for.
 *
 * @returns The index of the target element in the array if found, or -1 if not found.
 */
int posOfElemInInfinteSortedArray(vector<int> &nums, int target)
{
  int low = 0, high = 1;
  while (target > nums[high])
  {
    low = high;
    high = high * 2;
  }

  return binarySearch(nums, target, low, high);
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int target = 5;
  cout << "Index: " << posOfElemInInfinteSortedArray(nums, target) << endl;
}