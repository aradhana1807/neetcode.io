#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the kth largest element in a given array.
 *
 * Uses a min heap of size k to keep track of the k largest elements seen
 * so far. After going through the entire array, the top element of the min
 * heap is the kth largest element.
 *
 * Time complexity: O(n log k)
 * Space complexity: O(k)
 *
 * @param arr The input array.
 * @param k The value of k.
 *
 * @return The kth largest element in the array.
 */
int kthLargest(vector<int> &arr, int k)
{
  priority_queue<int, vector<int>, greater<int>> minh;

  for (int i = 0; i < arr.size(); i++)
  {
    minh.push(arr[i]);
    if (minh.size() > k)
    {
      minh.pop();
    }
  }

  return minh.top();
}

int main()
{
  vector<int> arr = {3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << kthLargest(arr, k);
}