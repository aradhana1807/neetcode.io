#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief Searches for the index of a target value in a sorted array in descending order.
   *
   * This function uses a binary search algorithm to efficiently locate the target value
   * within the given vector of integers sorted in descending order.
   *
   * @param nums A vector of integers sorted in descending order.
   * @param target The target integer value to search for in the array.
   * @return The index of the target value if found, otherwise returns -1.
   */
  int descSortedArray(vector<int> &nums, int target)
  {
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;

      if (nums[mid] == target)
      {
        return mid;
      }

      else if (nums[mid] > target)
      {
        start = mid + 1;
      }

      else
      {
        end = mid - 1;
      }
    }

    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {20, 17, 15, 14, 12, 9, 8, 6, 4};
  int target = 4;
  cout << "Index: " << s.descSortedArray(nums, target) << endl;
}

/* *
 * Method: int descSortedArray(vector<int> &nums, int target)
 * Description: Searches for the index of a target value in a sorted array in descending order.
 * Returns: The index of the target value if found, or -1 if not found.
 * Parameters:
  * nums: A sorted array of integers in descending order.
  * target: The target value to search for.

 * * Note: The method uses a binary search algorithm to efficiently search for the target value in the sorted array.
 */
