#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// Bubble Sort
int *bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
  return arr;
}

// Insertion Sort
int *insertionSort(int arr[], int n)
{
  int i, key, j;
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
    cout << endl;
  }
  return arr;
}

// Selection Sort
int *selectionSort(int arr[], int n)
{
  int i, j, min_idx;
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
    swap(&arr[min_idx], &arr[i]);
  }
  return arr;
}

// Shell Sort
int *shellSort(int arr[], int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {

    for (int i = gap; i < n; i += 1)
    {
      int temp = arr[i];

      int j;
      for (j = i; j >= gap && arr[j - gap] > temp;
           j -= gap)
        arr[j] = arr[j - gap];

      arr[j] = temp;
    }
  }
  return arr;
}

// Quick Sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

int *quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
  return arr;
}

// Merge Sort
void merge(int arr[], int l, int m, int r)
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
}

int *mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
  return arr;
}
