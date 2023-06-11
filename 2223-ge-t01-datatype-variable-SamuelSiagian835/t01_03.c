// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>

int main(int _argc, char **_argv){
int x;
int y;
int z;
int hasil;
int equality;

scanf("%d\n" ,&x);
scanf("%d\n" ,&y);
scanf("%d" ,&z);

hasil = x << y;
printf("%d\n", hasil);

equality = hasil == z;
printf("%d", equality);

  return 0;
}
