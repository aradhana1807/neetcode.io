#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
      int product = 1;
      for (int j = 0; j < n; j++)
      {
        if (i != j)
        {
          product *= nums[j];
        }
      }

      result[i] = product;
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> result = s.productExceptSelf(nums);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
}