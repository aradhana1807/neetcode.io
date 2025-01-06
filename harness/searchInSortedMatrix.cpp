#include <iostream>
#include <vector>

using namespace std;

// brute force O(n * m)

/**
 * @brief Searches for the target value in a matrix of integers.
 *
 * @param mat A 2D vector of integers.
 * @param target The target value to search for in the matrix.
 *
 * @return True if the target value is found, false otherwise.
 */
bool matrixSearch(vector<vector<int>> &mat, int target) {
  int n = mat.size(), m = mat[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == target)
        return true;
    }
  }

  return false;
}

// optimized O(m + n)

bool matrixSearchOptmized(vector<vector<int>> &mat, int target) {
  int n = mat.size(), m = mat[0].size();
  int i = 0, j = m - 1;

  while (i < n && j >= 0) {
    if (mat[i][j] == target)
      return true;

    else if (mat[i][j] > target)
      j--;

    else
      i++;
  }
  return false;
}

int main() {
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int target = 10;
  // cout << matrixSearch(mat, target) << endl;
  cout << matrixSearchOptmized(mat, target) << endl;
}