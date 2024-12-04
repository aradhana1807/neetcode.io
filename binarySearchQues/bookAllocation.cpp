#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

/**
 * Checks if the given array of integers can be distributed to k students such that
 * no student gets more than max books.
 *
 * @param arr the array of integers.
 * @param n the size of the array.
 * @param k the number of students.
 * @param max the maximum number of books a student can get.
 * @return true if the array can be distributed, false otherwise.
 */
bool isValid(vector<int> &arr, int n, int k, int max) {
  int student = 1;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (sum + arr[i] > max) {
      student++;
      sum = arr[i];
      if (student > k) {
        return false;
      }
    } else {
      sum += arr[i];
    }
  }
  return true;
}

/**
 * @brief Allocate books to k students such that each student gets
 * continuous set of books and the maximum number of pages assigned to
 * any student is minimized.
 *
 * @param nums A vector of integers denoting the number of pages in each book.
 * @param k The number of students.
 * @return The minimum number of pages that can be assigned to each student.
 */
int bookAlloaction(vector<int> &nums, int k) {
  int n = nums.size();
  int start = *max_element(nums.begin(), nums.end());
  int end = accumulate(nums.begin(), nums.end(), 0);

  int res = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (isValid(nums, n, k, mid)) {
      res = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}

int main() {
  vector<int> nums = {10, 20, 30, 40};
  int k = 2;
  cout << bookAlloaction(nums, k) << endl;
  return 0;
}