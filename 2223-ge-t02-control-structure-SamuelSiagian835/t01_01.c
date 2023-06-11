// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>

int main(int _argc, char **_argv) {

int mounth;
scanf("%d", &mounth);
      if( mounth == 1 ){
        printf("January\nFebruary\nMarch");
      }else if( mounth == 2){
        printf("February\nMarch\nApril");
      }else if( mounth == 3){
        printf("March\nApril\nMay");
      }else if( mounth == 4){
        printf("April\nMay\nJune");
      }else if( mounth == 5){
        printf("May\nJune\nJuly");
      }else if( mounth== 6){
        printf("June\nJuly\nAugust");
      }else if( mounth == 7){
        printf("July\nAugust\nSeptember");
      }else if( mounth == 8){
        printf("August\nSeptember\nOctober");
      }else if( mounth == 9){
        printf("September\nOctober\nNovember");
      }else if( mounth == 10){
        printf("October\nNovember\nDesember");
      }else if( mounth == 11){
        printf("November\nDecember\nNew year\nJanuary");
      }else if( mounth == 12){
        printf("December\nNew year\nJanuary\nFebruary");
      }else{ 
        printf("Invalid Input\n");
      }
      

  return 0;
}
