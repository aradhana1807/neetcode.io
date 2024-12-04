#include <iostream>
#include <vector>
using namespace std;

/**
 * Searches for the index of a target value in a rotated sorted array.
 *
 * This function uses a binary search algorithm to efficiently locate the target value
 * within the given vector of integers sorted in either ascending or descending order.
 *
 * @param nums A vector of integers sorted in either ascending or descending order.
 * @param n The size of the array.
 * @param target The target integer value to search for in the array.
 * @return The index of the target value if found, otherwise returns -1.
 */
int searchInRotatednumsay(vector<int> &nums, int n, int target) {
  int start = 0, end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    if (nums[start] <= nums[mid]) {
      if (target >= nums[start] && target <= nums[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    else {
      if (target >= nums[mid] && target <= nums[end]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    mid = start + (end - start) / 2;
  }
  return -1;
}

int main() {
  vector<int> nums = {4, 5, 6, 7, 1, 2};
  int n = nums.size();
  int target = 2;
  cout << searchInRotatednumsay(nums, n, target) << endl;
  return 0;
}