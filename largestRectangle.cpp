#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> NSL(vector<int> &arr, int n) {
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

  vector<int> NSR(vector<int> &arr, int n) {
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

  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> nsl = NSL(heights, n);
    vector<int> nsr = NSR(heights, n);
    long long area = 0;

    for (int i = 0; i < n; i++) {
      long long l = nsl[i];
      long long r = nsr[i];
      area = max(area, (r - l - 1) * heights[i]);
    }
    return area;
  }
};
