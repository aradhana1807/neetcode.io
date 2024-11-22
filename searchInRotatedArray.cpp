#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(vector<int> &arr, int n, int target)
{
  int start = 0, end = n - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }

    if (arr[start] <= arr[mid])
    {
      if (target >= arr[start] && target <= arr[mid])
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }

    else
    {
      if (target >= arr[mid] && target <= arr[end])
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    mid = start + (end - start) / 2;
  }
  return -1;
}

int main()
{
  vector<int> arr = {4, 5, 6, 7, 1, 2};
  int n = arr.size();
  int target = 2;
  cout << searchInRotatedArray(arr, n, target) << endl;
  return 0;
}