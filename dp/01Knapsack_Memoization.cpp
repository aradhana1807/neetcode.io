#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &t) {
  if (n == 0 || w == 0) {
    return 0;
  }

  if (t[n][w] != -1) {
    return t[n][w];
  }

  else if (wt[n - 1] < w) {
    return t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, t), knapsack(wt, val, w, n - 1, t));
  }

  else if (wt[n - 1] > w) {
    return t[n][w] = knapsack(wt, val, w, n - 1, t);
  }

  return 0;
}

int main() {
  vector<int> wt = {1, 3, 4, 5};
  vector<int> val = {1, 4, 5, 7};
  int w = 7;
  int n = wt.size();
  vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
  cout << knapsack(wt, val, w, n, t);
}