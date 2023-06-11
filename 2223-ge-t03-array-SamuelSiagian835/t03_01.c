// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>

  int main(int _argc, char **_argv)
{
  int n, tinggi, rendah;
  scanf("%i", &n);
  int data[n];
  int i;
  for (i=0; i<n; i++) {
      scanf ("%i", &data[i]);
  }
  
  tinggi = data[0];
  rendah = data[0];
  for (i=0; i<n; i++) {
      if (data[i]>tinggi) {
          tinggi = data[i];
      }                                                               
  }
  for (i=0; i<n; i++) {
    if (data[i]<rendah) {
        rendah = data[i];
    }
  }
  printf("%d\n", rendah);
  printf("%d", tinggi);

  return 0;
}
