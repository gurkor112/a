#include "io.h"

void CheckAndSwitch(char * to, char* from,   int length)
{
    if (strlen(to) > length)
    {
        strcpy(to, "u");
    }
    else
    {
        strcpy(to, from);
    }
    
}

  int AllNumbers(char *s,   int length)
{
    int i;
    for (i = 0; i < length; ++i)
    {
        if (!isdigit(s[i]))
        {
            printf("Du skrev inte in ett tal!\n");
            return 0;
        }
    }
    return 1;
}


int SafeString(char * s,   int length)
{
    if(!fgets(s, length - 1, stdin))
    {
        return 0;
    }
    if(!strchr(s, '\n'))
    {
        while( fgetc(stdin) != '\n');
    }
    else
    {
        strtok(s, "\n");
    }
    
    return 1; 
}

  int SafeInt()
{   
    char s[MAXLENGTH];
    do
    {
        SafeString(s, MAXLENGTH);
    }
    while(!AllNumbers(s, strlen(s)));
    return atoi(s);
}

void PrintList(car_t * cars,   int curr)
{
    int i;
    for (i = 0; i < curr; ++i)
    {
        printf("%s  %d år \n\n\tBil information:\n\tBiltyp: %s \n\tBilmärke: %s\n\tRegestreringsnummer: %s\n", 
        cars[i].owner.name, cars[i].owner.age, cars[i].type, cars[i].brand, cars[i].reg);
    }
}

void PrintAt(car_t * cars,   int curr)
{
    printf("Vilken position vill du skriva ut (index börjar på ett)?: ");
      int pos  = SafeInt() - 1;
    if (pos >= curr)
    {
        printf("Det finns inget fordon där!\n");
        return;
    }
    printf("%s  %d år \n\n\tBil information:\n\tBiltyp: %s \n\tBilmärke: %s\n\tRegestreringsnummer: %s\n", 
        cars[pos].owner.name, cars[pos].owner.age, cars[pos].type, cars[pos].brand, cars[pos].reg);
}


int ReadFromFile(car_t *cars, int size)
{
    FILE * file = fopen(INFILE, "r");
    if(!file)
    {
        printf("Kunde inte öppna fil!\n");
        return 0;
    }
    char name[NAMELENGTH], type[TYPELENGTH], brand[BRANDLENGTH], reg[REGLENGTH];
    int age;
    int res;
    int curr = 0;
    while(1)
    {
        res = fscanf(file,"%s %d %s %s %s", name, &age, type, brand, reg);
           
        if (res == EOF || curr >= size)
        {
            fclose(file);
            return curr;
        }
        
        CheckAndSwitch(cars[curr].type, type, TYPELENGTH);
        CheckAndSwitch(cars[curr].brand, brand, BRANDLENGTH);
        CheckAndSwitch(cars[curr].reg, reg, REGLENGTH);
        CheckAndSwitch(cars[curr].owner.name, name, NAMELENGTH);
        cars[curr].owner.age = age;
        ++curr; 
    }
}

void SaveToFile(car_t *cars,   int curr)
{
    FILE * file = fopen(INFILE, "w");
    if(!file)
    {
        printf("Kunde inte öppna filen!\n");
    }
    int i;
    for (i = 0; i < curr; ++i)
    {
        fprintf(file,"%s %d %s %s %s ", cars[i].owner.name, cars[i].owner.age, cars[i].type, cars[i].brand, cars[i].reg);
    }
    fclose(file);
}