// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>

int main(int _argc, char **_argv)
{
  int numerik1;
  char huruf;
  int numerik2;
  int numerik3;
  float numerik4;

  scanf("%d\n",&numerik1);
  scanf("%c\n",&huruf);
  scanf("%d\n",&numerik2);
  scanf("%d",&numerik3);
  scanf("%f",&numerik4);


  printf("%d\n",numerik1);
  printf("%c\n",huruf);
  printf("%d\n",numerik2);
  printf("%d\n",numerik3);
  printf("%.2f",numerik4);

  return 0;
}
