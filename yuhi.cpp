#include <iostream>
using namespace std;
#include <queue>

class HEAP
{

public:
  int arr[100];
  int size;

  void insertion(int value)
  {
    size = size + 1;
    int index = size;
    arr[index] = value;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[parent] < arr[index])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }

      else
      {
        return;
      }
    }
  }

  void delete()
  {
    if (size == 0)
    {
      cout << "empty" << endl;
      return;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i < size)
    {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if (leftIndex < size && arr[leftIndex] > arr[i])
      {
        swap(arr[leftIndex], arr[i]);
        i = leftIndex;
      }

      else if (rightIndex < size && arr[rightIndex] > arr[i])
      {
        swap(arr[rightIndex], arr[i]);
        i = rightIndex;
      }

      else
      {
        return;
      }
    }
  }
};