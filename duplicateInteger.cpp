#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        // brute force O(n^2)
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.hasDuplicate(nums) << endl;
    return 0;
}
