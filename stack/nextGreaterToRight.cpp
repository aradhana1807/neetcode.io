#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * @brief Finds the next greater element to the right of each element in a given array.
 *
 * This function takes a given array and returns a new array where each element is the next
 * greater element to the right. If there is no greater element, the function returns -1.
 *
 * @param arr The given array.
 *
 * @returns A new array where each element is the next greater element to the right.
 */
vector<int> nextGreater(vector<int> &arr)
{
  stack<int> st;
  vector<int> v;
  int n = arr.size();

  for (int i = n - 1; i >= 0; i--)
  {
    if (st.size() == 0)
    {
      v.push_back(-1);
    }

    else if (st.size() > 0 && st.top() > arr[i])
    {
      v.push_back(st.top());
    }

    else if (st.size() > 0 && st.top() <= arr[i])
    {
      while (st.size() > 0 && st.top() <= arr[i])
      {
        st.pop();
      }

      if (st.size() == 0)
      {
        v.push_back(-1);
      }

      else
      {
        v.push_back(st.top());
      }
    }

    st.push(arr[i]);
  }

  reverse(v.begin(), v.end());
  return v;
}

int main()
{
  vector<int> v = {1, 3, 2, 4};
  vector<int> v1 = {4, 3, 2, 1};
  vector<int> ans = nextGreater(v);
  vector<int> ans1 = nextGreater(v1);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  cout << endl;

  for (int i = 0; i < ans1.size(); i++)
  {
    cout << ans1[i] << " ";
  }

  return 0;
}