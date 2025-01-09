#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Finds the sum of three integers in the array that is closest to the target.
 *
 * This function iterates through all possible combinations of three integers in the
 * given vector `nums` and calculates their sum. It returns the sum that is closest
 * to the specified target value. If there is a sum that matches the target exactly,
 * the function returns that sum immediately.
 *
 * Time complexity: O(n^3), where n is the size of the `nums` vector.
 * Space complexity: O(1), as no additional space proportional to the input size is used.
 *
 * @param nums A vector of integers to search through.
 * @param target The target sum to approach.
 * 
 * @return The sum of three integers from `nums` that is closest to the target.
 */

int threeSumClosest(vector<int> &nums, int target) {
  int n = nums.size();
  int closest = nums[0] + nums[1] + nums[2];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum == target) {
          return sum;
        }
        if (abs(sum - target) < abs(closest - target)) {
          closest = sum;
        }
      }
    }
  }

  return closest;
}

int main() {
  vector<int> nums = {-1, 2, 1, -4};
  int target = 1;
  cout << threeSumClosest(nums, target) << endl;
  return 0;
}
