#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Searches for the index of a target value in a sorted array.
   *
   * This function performs a binary search on a sorted array to find the target value.
   * It handles both ascending and descending order arrays by determining the order
   * based on the first and last elements of the array.
   *
   * @param nums A vector of integers sorted in either ascending or descending order.
   * @param target The target integer value to search for in the array.
   * @return The index of the target value if found, otherwise returns -1.
   */
  int orderAgnosticSearch(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    bool isAscending = nums[start] < nums[end];

    while (start <= end) {
      int mid = start + (end - start) / 2;

      if (nums[mid] == target)
        return mid;

      if (isAscending) {
        if (nums[mid] < target) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      } else {
        if (nums[mid] < target) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }

      mid = start + (end - start) / 2;
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {7, 6, 5, 4, 3, 2, 1};
  vector<int> nums2 = {0, 1, 2, 3, 4};
  int target = 4;

  cout << s.orderAgnosticSearch(nums1, target) << endl;
  cout << s.orderAgnosticSearch(nums2, target) << endl;
}