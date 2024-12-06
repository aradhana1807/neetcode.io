#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * @brief Finds the nearest smaller element to the left of each element in a given array.
 *
 * @param arr The given array.
 *
 * @returns A new array where each element is the nearest smaller element to the left of
 * the corresponding element in the given array. If there is no smaller element, the function
 * returns -1.
 */
vector<int> nearestSmallerToLeft(vector<int> &arr) {
  vector<int> v;
  stack<int> st;
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    if (st.size() == 0) {
      v.push_back(-1);
    }

    else if (st.size() > 0 && st.top() < arr[i]) {
      v.push_back(st.top());
    }

    else if (st.size() > 0 && st.top() >= arr[i]) {
      while (st.size() > 0 && st.top() >= arr[i]) {
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
  return v;
}

int main() {
  vector<int> v = {4, 5, 2, 10, 8};
  vector<int> ans = nearestSmallerToLeft(v);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}