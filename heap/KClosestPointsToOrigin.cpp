#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the k closest points to the origin in a 2D plane.
 *
 * The function takes a vector of 2D points and an integer k as input, and
 * prints the k closest points to the origin in descending order of their
 * distance from the origin.
 *
 * The function uses a priority queue to keep track of the k closest points
 * seen so far. The priority queue is implemented as a max heap of size k.
 * The heap is ordered by the distance of the points from the origin, with
 * the closest point at the top of the heap.
 *
 * After going through all the points, the function prints the k closest points
 * in descending order of their distance from the origin.
 *
 * Time complexity: O(n log k)
 * Space complexity: O(k)
 *
 * @param points A vector of 2D points.
 * @param k The number of closest points to find.
 */
void kClosest(vector<vector<int>> &points, int k)
{
  priority_queue<pair<int, pair<int, int>>> maxh;
  pair<int, pair<int, int>> p;
  for (int i = 0; i < points.size(); i++)
  {
    maxh.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
    if (maxh.size() > k)
    {
      maxh.pop();
    }
  }

  while (maxh.size() > 0)
  {
    pair<int, int> p = maxh.top().second;
    cout << p.first << " " << p.second << endl;
    maxh.pop();
  }
}

int main()
{
  vector<vector<int>> v = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
  kClosest(v, 2);
  return 0;
}