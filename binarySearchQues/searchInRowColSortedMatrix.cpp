#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Searches for the target value in a matrix that is sorted in both
 * row-wise and column-wise order.
 *
 * @param matrix A 2D vector of integers that is sorted in both row-wise and
 * column-wise order.
 * @param target The target value to search for in the matrix.
 *
 * @return A pair of integers where the first element is the row index and the
 * second element is the column index of the target value if found, otherwise
 * returns {-1, -1}.
 */
pair<int, int> searchMatrix(vector<vector<int>> &matrix, int target)
{
  int m = matrix.size();    // row
  int n = matrix[0].size(); // column
  int i = 0;                // row
  int j = n - 1;            // column
  while (i >= 0 && i < m && j >= 0 && j < n)
  {
    if (matrix[i][j] == target)
      return {i, j};
    else if (matrix[i][j] > target)
      j--;
    else
      i++;
  }
  return {-1, -1};
}

int main()
{
  vector<vector<int>> matrix = {{1, 2, 3, 10}, {4, 5, 6, 20}, {7, 8, 9, 30}};
  int target = 7;
  pair<int, int> ans = searchMatrix(matrix, target);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}

/*
   * @brief Searches for the target value in a matrix that is sorted in both
   * row-wise and column-wise order.
   *
   * @param matrix A 2D vector of integers that is sorted in both row-wise and
   * column-wise order.
   * @param target The target value to search for in the matrix.
   *
   * @return True if the target value is found, false otherwise.
class Solution
{
public:
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int m = matrix.size();    // row
  int n = matrix[0].size(); // column
  int i = 0;                // row
  int j = n - 1;            // column
  while (i >= 0 && i < m && j >= 0 && j < n)
  {
    if (matrix[i][j] == target)
      return true;

    else if (matrix[i][j] > target)
      j--;
    else
      i++;
  }
  return false;
}
};
*/
