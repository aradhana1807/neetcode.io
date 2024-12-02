#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

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