#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
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