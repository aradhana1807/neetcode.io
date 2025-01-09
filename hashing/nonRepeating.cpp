#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Finds the first non-repeating element in an array.
 *
 * This function takes an array of integers and returns the first element
 * that does not repeat. If all elements repeat or the array is empty,
 * the function returns 0.
 *
 * @param arr The array of integers.
 * @param n The number of elements in the array.
 *
 * @returns The first non-repeating element or 0 if none exists.
 */

int firstNonRepeating(int arr[], int n) {
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  // for (int i = 0; i < n; i++) {
  //   if (mp[arr[i]] == 1)
  //     return arr[i];
  // }

  for (int i = 0; i < n; i++) {
    int key = arr[i];
    auto itr = mp.find(key);
    if (itr->second == 1)
      return key;
  }
  return 0;
}

int main() {
  int arr[] = {10, 5, 3, 4, 3, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << firstNonRepeating(arr, n);
}