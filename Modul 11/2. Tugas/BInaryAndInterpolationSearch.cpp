#include <iostream>
using namespace std;

int data[100];
int N = 0;
bool sorted = false;

int interpolationSearch(int x)
{
  int lo = 0, hi = (N - 1);
  while (lo <= hi && x >= data[lo] && x <= data[hi])
  {
    if (lo == hi)
    {
      if (data[lo] == x)
        return lo;
      return -1;
    }
    int pos = lo + (((double)(hi - lo) / (data[hi] - data[lo])) * (x - data[lo]));
    if (data[pos] == x)
      return pos;
    if (data[pos] < x)
      lo = pos + 1;
    else
      hi = pos - 1;
  }
  return -1;
}

int binarySearch(int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    if (data[mid] == x)
      return mid;

    if (data[mid] > x)
      return binarySearch(l, mid - 1, x);

    return binarySearch(mid + 1, r, x);
  }

  return -1;
}

void bubbleSort()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (data[j] > data[j + 1])
      {
        int temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
  sorted = true;
}

void tampil()
{
  if (N == 0)
  {
    cout << "Data kosong." << endl;
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      cout << data[i] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  int pilihan;
  while (true)
  {
    system("cls");
    tampil();

    cout << "Binary Search and Interpolation Search" << endl;
    cout << "1. Input data" << endl;
    cout << "2. Sort data" << endl;
    cout << "3. Binary Search" << endl;
    cout << "4. Interpolation Search" << endl;
    cout << "0. Exit" << endl;
    cout << "Menu: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      cout << "Input jumlah data: ";
      cin >> N;
      cout << endl;

      cout << "Input data-data: " << endl;
      for (int i = 0; i < N; i++)
      {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
      }
      cout << endl;
      sorted = false;
      break;

    case 2:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        bubbleSort();
      }
      break;

    case 3:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
      }
      else if (!sorted)
      {
        cout << "Urutkan data terlebih dahulu." << endl;
      }
      else
      {
        int x;
        cout << "Input data yang ingin dicari: ";
        cin >> x;

        int result = binarySearch(0, N - 1, x);
        if (result != -1)
        {
          cout << "Data ditemukan pada index ke-" << result + 1 << endl;
        }
        else
        {
          cout << "Data tidak ditemukan." << endl;
        }
      }
      system("pause");
      break;

    case 4:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
      }
      else if (!sorted)
      {
        cout << "Urutkan data terlebih dahulu." << endl;
      }
      else
      {
        int x;
        cout << "Input data yang ingin dicari: ";
        cin >> x;

        int result = interpolationSearch(x);
        if (result != -1)
        {
          cout << "Data ditemukan pada index ke-" << result + 1 << endl;
        }
        else
        {
          cout << "Data tidak ditemukan." << endl;
        }
      }
      system("pause");
      break;

    default:
      cout << "Salah" << endl;
      exit(1);
      break;
    }
  }
}