#include <iostream>
using namespace std;

int findPivot(int array[], int size)
{
  int left = 0;
  int right = size - 1;

  while (left < right)
  {
    int mid = left + (right - left) / 2;

    if (array[mid] > array[right])
    {
      left = mid + 1;
    }
    else
    {
      right = mid;
    }
  }

  return left;
}

int main()
{
  int rotatedArray[] = {7, 8, 1, 2, 3, 4, 5, 6};
  int size = sizeof(rotatedArray) / sizeof(rotatedArray[0]);

  int pivotIndex = findPivot(rotatedArray, size);

  cout << "The pivot is at index: " << pivotIndex << endl;

  return 0;
}