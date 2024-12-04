#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * @brief Prints the kth largest element in a given array.
 *
 * Uses a min heap of size k to keep track of the k largest elements seen
 * so far. After going through the entire array, the top element of the min
 * heap is the kth largest element. The function prints the kth largest element
 * and all the elements larger than it.
 *
 * Time complexity: O(n log k)
 * Space complexity: O(k)
 *
 * @param nums The input array.
 * @param k The value of k.
 */
void findKthLargest(vector<int> &nums, int k) {
  priority_queue<int, vector<int>, greater<int>> minh;
  int i;
  for (i = 0; i < nums.size(); i++) {
    minh.push(nums[i]);
    if (minh.size() > k) {
      minh.pop();
    }
  }

  while (minh.size() != 0) {
    cout << minh.top() << " ";
    minh.pop();
  }
}

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  findKthLargest(nums, k);
}