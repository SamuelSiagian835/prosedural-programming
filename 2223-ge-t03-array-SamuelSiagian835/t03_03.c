// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    // Pindahkan elemen dari arr[0..i-1], yang lebih besar dari key,
    // ke posisi setelah posisi mereka saat ini
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main(int _argc, char **_argv)
{
  // codes
  int size, max, min;
  scanf("%d", &size);

  int arr[100];
  max = arr[0];
  min = arr[0];
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);    
  }
  float summin, has;
  has=arr[0]+arr[1];
  summin=has/2;

  for (int i = 2; i < 100; i++)
  {
    scanf("%d", &arr[i]);    
  }
  float summbig, have;
  have=arr[2]+arr[3];
  summbig=have/2;

  insertionSort(arr, size);

  // for (int i = 0; i < size; i++)
  // {
  //   printf("%d ", arr[i]);
  // }

  printf("%d\n", arr[0]);
  printf("%d\n", arr[size - 1]);
  printf("%.2f\n",summin);
  printf("%.2f\n",summbig);

  return 0;
}