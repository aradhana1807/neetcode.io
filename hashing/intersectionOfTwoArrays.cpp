#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int intersectionOfTwoArrays(int arr1[], int arr2[], int m, int n) {
  unordered_set<int> s;
  unordered_set<int> s1;
  int count = 0;

  for (int i = 0; i < m; i++) {
    s.insert(arr1[i]);
  }

  for (int i = 0; i < n; i++) {
    int key = arr2[i];
    if (s.find(key) != s.end()) {
      count++;
      s.erase(key);
    }
  }

  return count;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {2, 4};

  int m = sizeof(arr1) / sizeof(arr1[0]);
  int n = sizeof(arr2) / sizeof(arr2[0]);

  cout << intersectionOfTwoArrays(arr1, arr2, m, n);
}