#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Returns the kth smallest element in a given array.
 *
 * Uses a max heap of size k to keep track of the k smallest elements seen
 * so far. After going through the entire array, the top element of the max
 * heap is the kth smallest element.
 *
 * Time complexity: O(n log k)
 * Space complexity: O(k)
 *
 * @param arr The input array.
 * @param k The value of k.
 *
 * @return The kth smallest element in the array.
 */

int kThSmallestElem(vector<int> &arr, int k)
{
  priority_queue<int> maxh;
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    maxh.push(arr[i]);
    if (maxh.size() > k)
    {
      maxh.pop();
    }
  }

  return maxh.top();
}

int main()
{

  vector<int> arr = {2, 5, 6, 3, 1, 9, 8};
  int k = 3;
  cout << kThSmallestElem(arr, k) << endl;
}
