#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Checks if there exists a pair of elements in the given array whose sum is equal to k.
 *
 * @param arr The input array of integers.
 * @param n The size of the input array.
 * @param k The target sum.
 *
 * @returns True if such a pair exists, false otherwise.
 */
bool hasArrayTwoCandidates(int arr[], int n, int k) {
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    int key = itr->first;
    int val = itr->second;
    int pair = k - key;

    if (pair == key) {
      if (val > 1) {
        return true;
      }

      else {
        if (mp.find(pair) != mp.end())
          return true;
      }
    }
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 6;
  cout << hasArrayTwoCandidates(arr, n, k);
}