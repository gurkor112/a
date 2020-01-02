#include "main.h"



person_t MakePerson(char* name,   int age)
{
    person_t toReturn;
    CheckAndSwitch(toReturn.name, name, NAMELENGTH);

    toReturn.age = age;
    return toReturn;
}

car_t MakeCar(char* type, char* brand, char* reg, person_t owner)
{
    car_t toReturn;
    CheckAndSwitch(toReturn.type, type, TYPELENGTH);
    CheckAndSwitch(toReturn.brand, brand, BRANDLENGTH);
    CheckAndSwitch(toReturn.reg, reg, REGLENGTH);
    toReturn.owner = owner;
    return toReturn;
}

void SortList(car_t * cars,   int curr)
{
    int i, j;
    car_t temp;
    int needSorting = 1;
    for(i = 0; i < curr && needSorting; ++i)
    {
        needSorting = 0;
        for (j = 0; j < curr - j - 1; ++j)
        {
            if (0 < strcmp(cars[i].brand, cars[i + 1].brand))
            {
                temp = cars[i];
                cars[i] = cars[i + 1];
                cars[i + 1] = temp;
            }
        }
    }
}

void AllUpper(char* s,   int length)
{
    int i;
    for(i = 0; i < length; ++i)
    {
        s[i] = toupper(s[i]);
    }
}

void AddCar(car_t* cars, int *curr)
{
    if (*curr >= AMOUNT)
    {
        printf("Det är fullt med fordon\n");
        return;
    }
    char name[NAMELENGTH];
    printf("Vad heter ägaren?: ");
    SafeString(name, NAMELENGTH);
    printf("Hur gammal är ägaren?: ");
    int age = SafeInt();
    person_t person = MakePerson(name, age);

    char type[TYPELENGTH];
    printf("Vilken typ av bil är det?: ");
    SafeString(type, TYPELENGTH);
    char brand[BRANDLENGTH];
    printf("Vilket märke är det?: ");
    SafeString(brand, BRANDLENGTH);
    AllUpper(brand, strlen(brand));
    char reg[REGLENGTH];
    printf("Vad har fordonet för regestreringsnummer?: ");
    SafeString(reg, REGLENGTH);
    cars[*curr] = MakeCar(type, brand, reg, person);
    *curr = *curr + 1;

}

void RemoveCar(car_t* cars,  int *curr)
{
    printf("Skriv position (indexet börjar på ett): ");
      int pos  = SafeInt() - 1;
    if (pos >= *curr)
    {
        printf("Finns inget fordon där!\n");
        return;
    }
    int i;
    for(i = pos; i < *curr; ++i)
    {
        cars[i] = cars[i + 1];
    }
    *curr = *curr - 1;
}

int main()
{

    car_t *cars;
    cars = (car_t *)malloc(AMOUNT * sizeof(car_t));
    int curr = ReadFromFile(cars, AMOUNT);

    int option, loop;
    loop = 1;
    while(loop)
    {
        printf("Välj ett alternativ\n\t1. Lägg till ett fordon\n");
        printf("\t2. Ta bort ett fordon\n");
        printf("\t3. Sortera efter bilmärke\n");
        printf("\t4. Skriv ut information om ett fordon\n");
        printf("\t5. Skriv ut fordonsregistret\n");
        printf("\t6. AVSLUTA!\n");

        option = SafeInt();


        switch (option)
        {
            case 1:
            AddCar(cars, &curr);
            break;
            case 2:
            RemoveCar(cars, &curr);
            break;
            case 3:
            SortList(cars, curr);
            break;
            case 4:
            PrintAt(cars, curr);
            break;
            case 5:
            PrintList(cars, curr);
            break;
            case 6:
            SaveToFile(cars, curr);
            loop = 0;
            break;
            default:
            printf("\" %d\" är inte ett giltigt alternativ", option);
            break;
        }

    }
    free(cars);
    return 0;

}