#include <bits/stdc++.h>
using namespace std;

int rainwaterTrapping(vector<int> &arr, int size) {
  int mxl[size];
  int mxr[size];

  mxl[0] = arr[0];
  for (int i = 1; i < size; i++) {
    mxl[i] = max(mxl[i - 1], arr[i]);
  }

  mxr[size - 1] = arr[size - 1];
  for (int i = size - 2; i >= 0; i--) {
    mxr[i] = max(mxl[i + 1], arr[i]);
  }

  int water[size];
  for (int i = 0; i < size; i++) {
    water[i] = min(mxl[i], mxl[i] - arr[i]);
  }

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum = sum + water[i];
  }

  return sum;
}

int main() {
  vector<int> arr = {3, 0, 0, 2, 0, 4};
  int size = arr.size();
  cout << rainwaterTrapping(arr, size);
}