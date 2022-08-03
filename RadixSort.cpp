#include <iostream>
using namespace std;

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max] = {0};

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixsort(int array[], int size) {

  int max = getMax(array, size);

  for (int place = 1; max / place > 0; place *= 10)
    countSort(array, size, place);
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() {
  int array[] = {458, 5000, 12, 39, 2, 399};
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);
}