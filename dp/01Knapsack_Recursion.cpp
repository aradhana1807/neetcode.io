#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int w, int n) {
  if (n == 0 || w == 0) {
    return 0;
  }

  if (wt[n - 1] < w) {
    return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
  }

  else if (wt[n - 1] > w) {
    return knapsack(wt, val, w, n - 1);
  }

  return 0;
}

int main() {
  vector<int> wt = {1, 3, 4, 5};
  vector<int> val = {1, 4, 5, 7};
  int w = 7;
  int n = wt.size();
  cout << knapsack(wt, val, w, n);
}