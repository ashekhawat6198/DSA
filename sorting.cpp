#include <iostream>
using namespace std;

// SELECTION SORT                 DO IT AGAIN
void SelectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minValue = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minValue])
            {
                minValue = j;
            }
        }
        swap(array[minValue], array[i])
    }
}

// BUBBLE SORT

// better

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// optimized

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swaped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }

        if (swaped == false)
        {
            // already sorted
            break;
        }
    }
}

//  INSERTION SORT

void insertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = array[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (array[j] > temp)
            {
                array[j + 1] = array[j];
            }
            else
            {
                break;
            }
        }

        array[j + 1] = temp;
    }
}

int main()
{
    int array[5] = {6, 2, 8, 4, 10};
    SelectionSort(array, 5);
    printArr(array, 5);
}