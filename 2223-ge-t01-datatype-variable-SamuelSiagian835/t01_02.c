// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>

int main(int _argc, char **_argv)
{
float e;
float f;
float g;
float h;
float i;
float jumlah;
float rata_rata;

  scanf("%f", &e);
  scanf("%f", &f);
  scanf("%f", &g);
  scanf("%f", &h);
  scanf("%f", &i);

  jumlah = e + f + g + h + i;
  printf("%.3f\n", jumlah);

  rata_rata =  jumlah / 5;
  printf("%.3f\n", rata_rata);


  return 0;
}
