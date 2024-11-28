#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief Finds the index of the peak element in a mountain array.
   *
   * A mountain array is defined as an array that is first strictly increasing
   * and then strictly decreasing.
   *
   * Time complexity: O(log n)
   * Space complexity: O(1)
   *
   * @param arr the input mountain array
   * @return the index of the peak element
   */
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
      int mid = start + (end - start) / 2;

      if (arr[mid] > arr[mid + 1])
      {
        end = mid;
      }
      else
      {
        start = mid + 1;
      }
      mid = start + (end - start) / 2;
    }

    return start;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {0, 1, 0};
  cout << s.peakIndexInMountainArray(nums) << endl;
  return 0;
}