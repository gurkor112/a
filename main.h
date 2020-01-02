#pragma once
#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AMOUNT 10
#define NAMELENGTH 32
#define TYPELENGTH 32
#define BRANDLENGTH 32
#define REGLENGTH 16


struct person{
    char name[NAMELENGTH];
    unsigned int age;
};
typedef struct person person_t;

struct car{
    char type[TYPELENGTH];
    char brand[BRANDLENGTH];
    char reg[REGLENGTH];
    person_t owner;

};
typedef struct car car_t;

