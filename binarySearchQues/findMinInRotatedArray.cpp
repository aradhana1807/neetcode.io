#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start < end)
    {
      int mid = start + (end - start) / 2;

      if (nums[mid] < nums[end])
      {
        end = mid;
      }
      else
      {
        start = mid + 1;
      }
    }
    return nums[start];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {4, 5, 6, 7};
  cout << s.findMin(nums) << endl;
  return 0;
}