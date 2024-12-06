#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> &arr) {
  int n = arr.size();
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

vector<int> NSR(vector<int> &arr) {
  int n = arr.size();
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

long long MAH(vector<int> &arr) {
  int n = arr.size();
  vector<int> nsl = NSL(arr);
  vector<int> nsr = NSR(arr);
  long long area = 0;

  for (int i = 0; i < n; i++) {
    long long l = nsl[i];
    long long r = nsr[i];
    area = max(area, (r - l - 1) * arr[i]);
  }
  return area;
};

/**
 * @brief Finds the maximum area of a rectangle that can be formed using the elements of a given binary matrix.
 *
 * @param arr The given binary matrix.
 * @param n The number of rows in the given matrix.
 * @param m The number of columns in the given matrix.
 *
 * @returns The maximum area of the rectangle that can be formed using the elements of the given binary matrix.
 */
long long maxAreaRectangleBMatrix(vector<vector<int>> &arr, int n, int m) {
  vector<int> v;
  for (int j = 0; j < m; j++) {
    v.push_back(arr[0][j]);
  }

  long long int max_area = MAH(v);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        v[j] = 0;
      }

      else {
        v[j] = v[j] + arr[i][j];
      }
    }
    max_area = max(max_area, MAH(v));
  }

  return max_area;
};

int main() {
  vector<vector<int>> arr = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
  cout << maxAreaRectangleBMatrix(arr, 4, 4);
}