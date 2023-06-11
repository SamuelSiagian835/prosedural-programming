// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include "academic.h"
#include <stdio.h>

int main(int _argc, char **_argv) {

      struct student_t std_wiro =
      create_student("12S22999", "Wiro Sableng", "2022", "Information Systems");

      struct student_t std_jaka =
      create_student("12S22998", "Jaka Sembung", "2022", "Information Systems");

      struct course_t crs_vp =
      create_course("12S1102", "Visual Programming", 2, GRADE_D);

      struct course_t crs_pp =
      create_course("10S1002", "Procedural Programming", 2, GRADE_C);

  // re-implement the print_student(...)
  print_student(std_wiro);
  print_student(std_wiro);
  print_student(std_jaka);


  return 0;
}