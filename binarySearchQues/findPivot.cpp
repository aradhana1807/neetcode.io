#include <iostream>
using namespace std;

class Solution
{
public:
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
