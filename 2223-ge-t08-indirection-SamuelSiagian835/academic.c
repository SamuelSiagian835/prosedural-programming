// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) { 
    char *text = malloc(8);
    text[0] = '\0';

  switch(_grade) {
        case GRADE_A:  return "A";
        case GRADE_AB: return "AB";
        case GRADE_B:  return "B";
        case GRADE_BC: return "BC";
        case GRADE_C:  return "C";
        case GRADE_D:  return "D";
        case GRADE_E:  return "E";
        case GRADE_T:  return "T";
        default:       return "None";
    }
  return text; 
 }

float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    float performance = 0.0;
    if (_grade == GRADE_A) {
        performance = 4.0 * _credit;
    } else if (_grade == GRADE_AB) {
        performance = 3.5 * _credit;
    } else if (_grade == GRADE_B) {
        performance = 3.0 * _credit;
    } else if (_grade == GRADE_BC) {
        performance = 2.5 * _credit;
    } else if (_grade == GRADE_C) {
        performance = 2.0 * _credit;
    } else if (_grade == GRADE_D) {
        performance = 1.0 * _credit;
    } else {
        performance = 0.0;
    }
    return performance;
}

void print_course(struct course_t _course) {
     char *text = grade_to_text(_course.passing_grade);
  printf("%s|%s|%d|%s\n", _course.code, _course.name, _course.credit, text);

}

void print_student(struct student_t _student) {
    printf("%s|%s|%s|%s|%.2f\n", _student.id,_student.name, _student.year, _student.study_program, _student.gpa);
}

void print_enrollment(struct enrollment_t _enrollment) {
     char *text = grade_to_text(_enrollment.grade);
  float performance = calculate_performance(_enrollment.grade, _enrollment.course.credit);
  printf("%s|%s|%s|%.2f\n", _enrollment.course.code,_enrollment.student.id, text, performance);
}

void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size) {
                         int i;
  for(i = 0;i< _enrollment_size;i++){
    char *text = grade_to_text(_enrollments[i].grade);
    float performance = calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
    printf("%s|%s|%s|%.2f\n", _enrollments[i].course.code,_enrollments[i].student.id, text, performance);
    }
                       }

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade)
{
    struct course_t crs;

    strcpy(crs.code, _code);
    strcpy(crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;

    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)
{
    struct student_t std;

    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);
    std.gpa = GRADE_NONE;

    return std;
}

struct enrollment_t create_enrollment(struct course_t _course, struct student_t _student, char *_year,
                                      enum semester_t _semester)
{
    struct enrollment_t emt;

    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    emt.grade = GRADE_NONE;

    return emt;
}

void calculate_gpa(struct student_t *_student, struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size){
    int i;
    float total_performance = 0.00;
    int total_credit = 0;
    for(i=0 ; i < _enrollment_size ; i++){
        total_performance += calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
        total_credit += _enrollments[i].course.credit;
    }
    _student-> gpa = total_performance / total_credit;
}

void set_enrollment_grade(struct course_t _course, struct student_t _student, struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size, enum grade_t _grade)
{
    int i;
for(i=0; i<_enrollment_size; i++){

    if(strcmp(_enrollments[i].course.code, _course.code) == 0 && strcmp(_enrollments[i].student.id, _student.id) == 0){
      _enrollments[i].grade = _grade;
    }
  }
}