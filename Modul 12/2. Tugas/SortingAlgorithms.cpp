#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void print(int arr[], int N, int j)
{
  for (int i = 0; i < N; i++)
  {
    if (i == j)
    {
      cout << "'" << arr[j] << "' ";
    }
    else
      cout << arr[i] << " ";
  }
  cout << endl;
}

// Bubble Sort
int *bubbleSort(int arr[], int n)
{
  int i, j;
  print(arr, n, -1);
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
        print(arr, n, j + 1);
      }
    }
  }
  system("pause");
  return arr;
}

// Insertion Sort
int *insertionSort(int arr[], int n)
{
  int i, key, j;
  print(arr, n, -1);
  cout << endl;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    cout << "Key: " << key << endl;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
    print(arr, n, -1);
    cout << endl;
  }
  system("pause");
  return arr;
}

// Selection Sort
int *selectionSort(int arr[], int n)
{
  int i, j, min_idx;

  print(arr, n, -1);
  for (i = 0; i < n - 1; i++)
  {
    cout << endl;
    min_idx = i;

    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_idx])
      {
        min_idx = j;
      }
    }
    cout << "Min index : " << min_idx << endl;
    cout << "Min value : " << arr[min_idx] << endl;
    cout << "Swap with data[" << i << "]" << endl;
    swap(&arr[min_idx], &arr[i]);
    print(arr, n, min_idx);
  }
  system("pause");
  return arr;
}
