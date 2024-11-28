#include <iostream>
#include <vector>
using namespace std;

int firstOccurenceOfElem(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;
  int res = -1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (target == arr[mid])
    {
      res = mid;
      end = mid - 1;
    }

    else if (target < arr[mid])
    {
      end = mid - 1;
    }

    else
    {
      start = mid + 1;
    }
  }
  return res;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 8, 8};
  int target = 8;
  cout << firstOccurenceOfElem(arr, target) << endl;
}