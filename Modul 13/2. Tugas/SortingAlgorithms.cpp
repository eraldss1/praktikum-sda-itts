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

// Shell Sort
int *shellSort(int arr[], int n)
{
  print(arr, n, -1);
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    cout << "Gap : " << gap << endl;
    for (int i = gap; i < n; i += 1)
    {
      int temp = arr[i];

      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
      {
        arr[j] = arr[j - gap];
        print(arr, n, -1);
      }
      arr[j] = temp;
      print(arr, n, -1);
    }
  }
  system("pause");
  return arr;
}

// Quick Sort
int partition(int arr[], int low, int high, int n)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
      print(arr, n, -1);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  print(arr, n, -1);
  return (i + 1);
}

int *quickSort(int arr[], int low, int high, int n)
{
  print(arr, n, -1);
  cout << endl;
  if (low < high)
  {
    int pi = partition(arr, low, high, n);

    quickSort(arr, low, pi - 1, n);
    quickSort(arr, pi + 1, high, n);
  }
  return arr;
}

// Merge Sort
void merge(int arr[], int l, int m, int r, int n)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
  print(arr, n, -1);
}

int *mergeSort(int arr[], int l, int r, int n)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, n);
    mergeSort(arr, m + 1, r, n);

    merge(arr, l, m, r, n);
  }
  return arr;
}
