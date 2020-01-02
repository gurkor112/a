#pragma once
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLENGTH 32
#define INFILE "registry"

struct car;


int SafeString(char* s,  int length);

 int SafeInt();

void PrintList(struct car * cars,  int curr);

void PrintAt(struct car* cars,  int curr);

 int ReadFromFile(struct car* cars,  int size);

void CheckAndSwitch(char * to, char* from,  int length);

void SaveToFile(struct car* cars,  int curr);