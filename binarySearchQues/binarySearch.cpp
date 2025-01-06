#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * Searches for a target in a sorted array of integers using binary search.
   *
   * @param nums a sorted array of integers
   * @param target the target to search for
   * @return the index of the target if found, -1 otherwise
   */
  int search(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target)
        return mid;

      if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }

      mid = start + (end - start) / 2;
    }
    return -1;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  int result = solution.search(nums, target);
  cout << "Index of " << target << " is " << result << endl;
  return 0;
}