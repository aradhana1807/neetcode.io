#include <iostream>
using namespace std;
/**
 * @brief Finds the integer square root of a given number using binary search.
 *
 * @param n The number to find the square root of.
 *
 * @returns The integer square root of @p n, or -1 if no such square root exists.
 */
long long int sqrtInteger(int n)
{
  int start = 0, end = n;
  long long int mid = start + (end - start) / 2;
  long long int ans = -1;
  while (start <= end)
  {
    int sqr = mid * mid;
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
 * @brief Refines the square root approximation to a specified precision.
 *
 * This function takes an initial integer square root approximation of a number `n`
 * (provided by `tempSol`) and refines it to the given number of decimal places
 * specified by `precision`.
 *
 * @param n The number for which the square root is to be approximated.
 * @param precision The number of decimal places to which the square root should be refined.
 * @param tempSol The initial integer approximation of the square root of `n`.
 * @return A double representing the square root of `n` refined to the specified precision.
 */
double morePrecision(int n, int precision, int tempSol)
{
  double factor = 1;
  double ans = tempSol;
  for (int i = 0; i < precision; i++)
  {
    factor = factor / 10;
    for (double j = ans; j * j < n; j = j + factor)
    {
      ans = j;
    }
  }
  return ans;
}
int main()
{
  int n;
  cout << "Enter any number: " << endl;
  cin >> n;

  int tempSol = sqrtInteger(n);
  cout << "After precision: " << morePrecision(n, 3, tempSol);
  return 0;
}