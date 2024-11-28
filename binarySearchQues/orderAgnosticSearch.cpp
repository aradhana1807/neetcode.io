#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int orderAgnosticSearch(vector<int> &nums, int target)
  {
    int start = 0;
    int end = nums.size() - 1;

    bool isAscending = nums[start] < nums[end];

    while (start <= end)
    {
      int mid = start + (end - start) / 2;

      if (nums[mid] == target)
        return mid;

      if (isAscending)
      {
        if (nums[mid] < target)
        {
          start = mid + 1;
        }
        else
        {
          end = mid - 1;
        }
      }
      else
      {
        if (nums[mid] < target)
        {
          end = mid - 1;
        }
        else
        {
          start = mid + 1;
        }
      }

      mid = start + (end - start) / 2;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {7, 6, 5, 4, 3, 2, 1};
  vector<int> nums2 = {0, 1, 2, 3, 4};
  int target = 4;

  cout << s.orderAgnosticSearch(nums1, target) << endl;
  cout << s.orderAgnosticSearch(nums2, target) << endl;
}