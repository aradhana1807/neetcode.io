#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * Connects ropes together with minimal cost.
 *
 * This function takes a vector of integers representing the lengths of ropes 
 * and connects them into a single rope with the minimal cost. The cost of 
 * connecting two ropes is the sum of their lengths. The function uses a 
 * min-heap to repeatedly connect the two shortest ropes until only one rope 
 * remains.
 *
 * @param ropes A vector of integers representing the lengths of ropes.
 * @return The minimum cost of connecting all the ropes into one.
 */
int connectRopes(vector<int> &ropes)
{

  priority_queue<int, vector<int>, greater<int>> minH;

  for (int i = 0; i < ropes.size(); i++)
  {
    minH.push(ropes[i]);
  }

  int cost = 0;

  while (minH.size() > 1)
  {
    int first = minH.top();
    minH.pop();
    int second = minH.top();
    minH.pop();

    cost += first + second;
    minH.push(first + second);
  }

  return cost;
}

int main()
{

  vector<int> ropes = {1, 2, 3, 4, 5};
  cout << connectRopes(ropes);
}