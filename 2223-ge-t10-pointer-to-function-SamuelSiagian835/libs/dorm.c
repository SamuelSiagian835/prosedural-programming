#include "dorm.h"
#include <stdio.h>
#include <string.h>
#include "gender.h"



struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
    struct dorm_t dorm_;
    strcpy(dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.gender = _gender;
    dorm_.residents_num = 0;
    return dorm_;
}

void print_dorm(struct dorm_t *_dorm, int count){
    for (int i = 0; i < count; i++){

    if (_dorm[i].gender == GENDER_MALE){
        printf("%s|%d|male\n", _dorm[i].name, _dorm[i].capacity);
        } else if(_dorm[i].gender == GENDER_FEMALE){
            printf("%s|%d|female\n", _dorm[i].name,_dorm[i].capacity);
        }
    }
} 
void print_detaildorm(struct dorm_t *_dorm, int count){

    char jenis[10];
    strcpy(jenis, "|male");

    char type[10];
     strcpy(type, "|female");

    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender==0){
        printf("%s|%d%s|%d\n", _dorm[i].name, _dorm[i].capacity, jenis, _dorm[i].residents_num);
        } else if(_dorm[i].gender==1){
            printf("%s|%d%s|%d\n", _dorm[i].name, _dorm[i].capacity, type, _dorm[i].residents_num);
        }
    }
}

