#include <iostream>
#include <unordered_map>
using namespace std;

// bool subArrayExists(int arr[], int n) {
//   for (int i = 0; i < n; i++) {
//     int sum = 0;
//     for (int j = i; j < n; j++) {
//       if (sum == 0) {
//         return true;
//       } else {
//         return false;
//       }
//     }
//   }

//   return -1;
// }

bool isSubArrayExists(int arr[], int n) {
  unordered_map<int, int> mp;
  int sum = 0;
  mp[0] = -1;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (mp.find(sum) != mp.end()) {
      return true;
    } else {
      mp[sum] = i;
    }
  }
  return false;
}

int main() {
  int arr[] = {1, 3, -6, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << isSubArrayExists(arr, n);
}