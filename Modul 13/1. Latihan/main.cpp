#include <iostream>
#include <time.h>
#include "SortingAlgorithms.cpp"
using namespace std;

int data[100];
int N = 0;
bool sorted = false;

void randomData()
{
  int randomedArray[N];
  int visitedArray[N];

  memset(randomedArray, 0, sizeof(randomedArray));
  memset(visitedArray, 0, sizeof(visitedArray));
  for (int i = 0; i < N; i++)
  {
    srand(time(NULL));
    while (randomedArray[i] == 0)
    {
      int randomIndex = rand() % N;
      if (visitedArray[randomIndex] == 1)
      {
        continue;
      }

      randomedArray[i] = data[randomIndex];
      visitedArray[randomIndex] = 1;
    }
  }

  for (int i = 0; i < N; i++)
  {
    data[i] = randomedArray[i];
  }
}

void convertData(int *x)
{
  for (int i = 0; i < N; i++)
  {
    data[i] = *(x + i);
  }
}

void tampil()
{
  if (N == 0)
  {
    cout << "Data tidak ada." << endl;
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
    cout << "2. Random Current data" << endl;
    cout << "3. Sort data - Bubble Sort" << endl;
    cout << "4. Sort data - Insertion Sort" << endl;
    cout << "5. Sort data - Selection Sort" << endl;
    cout << "6. Sort data - Shell Sort" << endl;
    cout << "7. Sort data - Quick Sort" << endl;
    cout << "8. Sort data - Merge Sort" << endl;
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
        randomData();
      }
      break;

    case 3:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        int *x = bubbleSort(data, N);
        convertData(x);
      }
      break;

    case 4:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        int *x = insertionSort(data, N);
        convertData(x);
      }
      break;

    case 5:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        int *x = selectionSort(data, N);
        convertData(x);
      }
      break;

    case 6:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        int *x = shellSort(data, N);
        convertData(x);
      }
      break;

    case 7:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        int *x = quickSort(data, 0, N - 1);
        convertData(x);
      }
      break;

    case 8:
      if (N == 0)
      {
        cout << "Input data terlebih dahulu." << endl;
        system("pause");
      }
      else
      {
        int *x = mergeSort(data, 0, N - 1);
        convertData(x);
      }
      break;

    default:
      cout << "Salah" << endl;
      exit(1);
      break;
    }
  }
}