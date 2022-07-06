#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
  }

  return -1;
}

int *bubleSort(int arr[], int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

int main(void)
{
  int N;
  cout << "Input jumlah data: ";
  cin >> N;
  cout << endl;

  int arr[N];
  cout << "Input data-data: " << endl;
  for (int i = 0; i < N; i++)
  {
    cout << "Data ke-" << i + 1 << ": ";
    cin >> arr[i];
  }
  cout << endl;

  int *sorted = bubleSort(arr, N);
  for (int i = 0; i < N; i++)
  {
    arr[i] = *(sorted + i);
  }

  int x;
  cout << "Input data yang ingin dicari: ";
  cin >> x;

  int result = binarySearch(arr, 0, N - 1, x);
  (result == -1) ? cout << "Data tidak ditemukan"
                 : cout << "Data ditemukan di index ke - " << result + 1;
  return 0;
}
