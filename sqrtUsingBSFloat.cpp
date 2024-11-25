#include <iostream>
using namespace std;
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