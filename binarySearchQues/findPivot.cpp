#include <iostream>
using namespace std;

class Solution
{
public:
  /**
   * Finds the pivot element of a rotated sorted array.
   *
   * Time complexity: O(log n)
   * Space complexity: O(1)
   *
   * @param arr a rotated sorted array of distinct integers
   * @param n the size of the array
   * @return the index of the pivot element
   */
  int findPivot(int arr[], int n)
  {
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
      int mid = start + (end - start) / 2;

      if (arr[mid] >= arr[0])
      {
        start = mid + 1;
      }

      else
      {
        end = mid;
      }

      mid = start + (end - start) / 2;
    }
    return start;
  }
};
