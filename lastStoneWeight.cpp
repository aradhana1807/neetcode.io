#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief Finds the weight of the last stone left after repeatedly smashing
   *        the heaviest two stones together.
   *
   * The function takes a vector of integers representing the weights of stones
   * and returns the weight of the last stone left after repeatedly smashing
   * the heaviest two stones together. If all the stones are smashed, the
   * function returns 0.
   *
   * The function uses a priority queue to keep track of the heaviest stones.
   * The queue is ordered by the weight of the stones in descending order.
   *
   * Time complexity: O(n log n)
   * Space complexity: O(n)
   *
   * @param stones A vector of integers representing the weights of stones.
   *
   * @return The weight of the last stone left after repeatedly smashing the
   *         heaviest two stones together.
   */
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxH;

    for (int i = 0; i < stones.size(); i++) {
      maxH.push(stones[i]);
    }

    while (maxH.size() > 1) {
      int first = maxH.top();
      maxH.pop();
      int second = maxH.top();
      maxH.pop();
      if (first != second) {
        maxH.push(first - second);
      }
    }

    maxH.push(0);
    return maxH.top();
  };
};

int main() {
  vector<int> stones = {1, 3};
  Solution obj;
  cout << obj.lastStoneWeight(stones);
}
