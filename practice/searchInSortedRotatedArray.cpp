#include <iostream>
#include <vector>
using namespace std;

int searchInSortedRotatedArray(vector<int> &nums, int target) {
  int start = 0, end = nums.size() - 1;

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
  }
  return -1;
}

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 7;
  cout << searchInSortedRotatedArray(nums, target) << endl;
  return 0;
}