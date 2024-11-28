#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
  int res = -1;
  int n = letters.size();
  int start = 0, end = n - 1, mid;

  while (start <= end)
  {
    mid = start + (end - start) / 2;

    if (letters[mid] > target)
    {
      res = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }

  if (res == -1)
    return letters[0];

  return letters[res];
}

int main()
{
  vector<char> letters = {'a', 'c', 'f', 'j', 'k'};
  char target = 'f';
  cout << nextGreatestLetter(letters, target) << endl;
  return 0;
}