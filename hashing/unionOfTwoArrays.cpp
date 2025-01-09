#include <bits/stdc++.h>

#include <iostream>
#include <unordered_set>
using namespace std;

int countOfUnionOfTwoArrays(int arr1[], int arr2[], int n, int m) {
  unordered_set<int> s;

  for (int i = 0; i < n; i++) {
    s.insert(arr1[i]);
  }

  for (int i = 0; i < m; i++) {
    s.insert(arr2[i]);
  }

  return s.size();
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 2, 3};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  int m = sizeof(arr2) / sizeof(arr2[0]);

  cout << countOfUnionOfTwoArrays(arr1, arr2, n, m);
}