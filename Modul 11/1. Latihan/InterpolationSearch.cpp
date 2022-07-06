#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
  int lo = 0, hi = (n - 1);
  while (lo <= hi && x >= arr[lo] && x <= arr[hi])
  {
    if (lo == hi)
    {
      if (arr[lo] == x)
        return lo;
      return -1;
    }
    int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
    if (arr[pos] == x)
      return pos;
    if (arr[pos] < x)
      lo = pos + 1;
    else
      hi = pos - 1;
  }
  return -1;
}

int main()
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
  int index = interpolationSearch(arr, N, x);

  if (index != -1)
    cout << "Data ditemukan pada index ke-" << index + 1;
  else
    cout << "Data tidak ditemukan.";
  return 0;
}