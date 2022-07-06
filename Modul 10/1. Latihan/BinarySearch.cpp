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

int main(void)
{
  int N;
  cout << "Input jumlah data: ";
  cin >> N;
  cout << endl;

  int arr[N];
  cout << "Input data-data (berurut): " << endl;
  for (int i = 0; i < N; i++)
  {
    cout << "Data ke-" << i + 1 << ": ";
    cin >> arr[i];
  }
  cout << endl;

  int x;
  cout << "Input data yang ingin dicari: ";
  cin >> x;

  int result = binarySearch(arr, 0, N - 1, x);
  (result == -1) ? cout << "Data tidak ditemukan"
                 : cout << "Data ditemukan di index ke - " << result + 1;
  return 0;
}
