#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Finds the last occurrence of a target element in a sorted array.
 *
 * This function uses a binary search algorithm to efficiently locate the last
 * occurrence of the target element within the given vector of integers.
 *
 * @param nums A sorted array of integers.
 * @param target The target element to search for.
 *
 * @returns The index of the last occurrence of the target element if found, or
 * -1 if not found.
 */
int lastOccurenceOfElem(vector<int> &nums, int target) {
  int start = 0, end = nums.size() - 1;
  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) {
      res = mid;
      start = mid + 1;
    }

    else if (target < nums[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}

int main() {
  vector<int> arr = {4, 6, 7, 8, 8, 8, 9};
  int target = 8;
  cout << lastOccurenceOfElem(arr, target) << endl;
}