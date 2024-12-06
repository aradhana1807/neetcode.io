#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


/**
 * @brief Finds the nearest greater element to the right of each element in a given array.
 *
 * @param arr The given array.
 *
 * @returns A new array where each element is the nearest greater element to the right of
 * the corresponding element in the given array. If there is no greater element, the function
 * returns -1.
 */
vector<int> nearestGreaterToRight(vector<int> &arr) {
  stack<int> st;
  vector<int> v;
  int n = arr.size();

  for (int i = n - 1; i >= 0; i--) {
    if (st.size() == 0) {
      v.push_back(-1);
    }

    else if (st.size() > 0 && st.top() > arr[i]) {
      v.push_back(st.top());
    }

    else if (st.size() > 0 && st.top() <= arr[i]) {
      while (st.size() > 0 && st.top() <= arr[i]) {
        st.pop();
      }

      if (st.size() == 0) {
        v.push_back(-1);
      }

      else {
        v.push_back(st.top());
      }
    }

    st.push(arr[i]);
  }

  reverse(v.begin(), v.end());
  return v;
}

int main() {
  vector<int> v = {1, 3, 2, 4};
  vector<int> v1 = {4, 3, 2, 1};
  vector<int> ans = nearestGreaterToRight(v);
  vector<int> ans1 = nearestGreaterToRight(v1);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  cout << endl;

  for (int i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << " ";
  }

  return 0;
}