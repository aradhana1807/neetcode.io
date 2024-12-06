#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Finds the nearest smaller element to the left of each element in a given array.
   *
   * @param arr The given array.
   * @param n The size of the given array.
   *
   * @returns A new array where each element is the nearest smaller element to the left of
   * the corresponding element in the given array. If there is no smaller element, the function
   * returns -1.
   */
  vector<int> NSL(long long arr[], int n) {
    vector<int> left;
    stack<int> s;

    for (int i = 0; i < n; i++) {
      if (s.size() == 0)
        left.push_back(-1);

      else if (s.size() > 0 && arr[s.top()] < arr[i]) {
        left.push_back(s.top());
      }

      else if (s.size() > 0 && arr[s.top()] >= arr[i]) {
        while (s.size() != 0 && arr[s.top()] >= arr[i]) {
          s.pop();
        }

        if (s.size() == 0)
          left.push_back(-1);

        else if (s.size() > 0 && arr[s.top()] < arr[i]) {
          left.push_back(s.top());
        }
      }
      s.push(i);
    }
    return left;
  }
  /**
   * @brief Finds the nearest smaller element to the right of each element in a given array.
   *
   * @param arr The given array.
   * @param n The size of the given array.
   *
   * @returns A new array where each element is the nearest smaller element to the right of
   * the corresponding element in the given array. If there is no smaller element, the function
   * returns n.
   */
  vector<int> NSR(long long arr[], int n) {
    vector<int> right;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
      if (s.size() == 0)
        right.push_back(n);

      else if (s.size() > 0 && arr[s.top()] < arr[i]) {
        right.push_back(s.top());
      }

      else if (s.size() > 0 && arr[s.top()] >= arr[i]) {
        while (s.size() != 0 && arr[s.top()] >= arr[i]) {
          s.pop();
        }

        if (s.size() == 0)
          right.push_back(n);

        else if (s.size() > 0 && arr[s.top()] < arr[i]) {
          right.push_back(s.top());
        }
      }
      s.push(i);
    }
    reverse(right.begin(), right.end());
    return right;
  }
  /**
   * @brief Finds the maximum area of a histogram which can be formed using the elements of the given array.
   *
   * @param arr The given array.
   * @param n The size of the given array.
   *
   * @returns The maximum possible area of the histogram.
   */
  long long getMaxArea(long long arr[], int n) {
    vector<int> nsl = NSL(arr, n);
    vector<int> nsr = NSR(arr, n);
    long long area = 0;

    for (int i = 0; i < n; i++) {
      long long l = nsl[i];
      long long r = nsr[i];
      area = max(area, (r - l - 1) * arr[i]);
    }
    return area;
  }
};

int main() {
  long long arr[] = {2, 1, 5, 6, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  Solution s;
  cout << s.getMaxArea(arr, n);
}