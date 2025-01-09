#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Finds the index of the first repeating element in an array.
 *
 * @param arr The input array of integers.
 * @param n The size of the input array.
 *
 * @returns The index of the first repeating element if found, or -1 if not found.
 */
int firstRepeatingElement(int arr[], int n) {
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (int i = 0; i < n; i++) {
    int key = arr[i];
    auto itr = mp.find(key);
    if (itr->second > 1) {
      return i + 1;
    }
  }

  return -1;
}

int main() {
  int arr[] = {10, 5, 3, 4, 3, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << firstRepeatingElement(arr, n);
}