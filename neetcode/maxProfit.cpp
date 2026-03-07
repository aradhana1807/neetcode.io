#include <iostream>
#include <vector>
using namespace std;


// You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
// You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
// Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

// Example 1:
// Input: prices = [10,1,5,6,7,1]
// Output: 6
// Explanation: Buy prices[1] and sell prices[4], profit = 7 - 1 = 6.

// Example 2:
// Input: prices = [10,8,7,5,2]
// Output: 0
// Explanation: No profitable transactions can be made, thus the max profit is 0.

// Constraints:
// 1 <= prices.length <= 100
// 0 <= prices[i] <= 100

class Solution {
public:
  /**
   * Returns the maximum profit that can be achieved by buying and selling one NeetCoin.
   *
   * Given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
   * You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
   *
   * @param prices An integer array where prices[i] is the price of NeetCoin on the ith day.
   * @return The maximum profit that can be achieved.
   */

  int maxProfit(vector<int>& prices) {
    int n = prices.size(), profit = 0;
    int minVal = INT_MAX;
    for (int i = 0;i < n;i++) {
      minVal = min(minVal, prices[i]);
      profit = max(profit, prices[i] - minVal);
    }
    return profit;
  }
};
