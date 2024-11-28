#include <iostream>
using namespace std;
long long int binarySearch(int n)
{
  int start = 0, end = n;
  long long int mid = start + (end - start) / 2;
  long long int ans = -1;
  while (start <= end)
  {
    int sqr = mid * mid;
    /* code */
    if (sqr == n)
      return mid;
    if (sqr < n)
    {
      ans = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}

/**
 * @brief Computes the integer square root of a given number using binary search.
 *
 * @param num the number to compute the square root of
 *
 * @returns the integer square root of @p num
 */
int sqrtUsingBS(int num)
{
  return binarySearch(num);
}

int main()
{
  int num = 36;
  cout << sqrtUsingBS(num) << endl;
  return 0;
}