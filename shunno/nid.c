#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char first[10];
    char last[10];
} Name;

typedef struct
{
    int day;
    char month[4];
    int year;
} Date;

typedef struct
{
    Name full_name, father_name, mother_name;
    Date birth_date;
    long long ID;
} NID;

void printName(Name a)
{
    printf("%s %s", a.first, a.last);
}

void printDate(Date a)
{
    printf("%0d/%s/%d", a.day, a.month, a.year);
}

void printNID(NID a)
{
    printf("Full name: ");
    printName(a.full_name);
    printf("\nFather name: ");
    printName(a.father_name);
    printf("\nMother name: ");
    printName(a.mother_name);
    printf("\nDate of Birth: ");
    printDate(a.birth_date);
    printf("\nID: %lld", a.ID);
}

int scanName(Name *name)
{
    char first[10], last[10];
    if (scanf("%s %s", first, last) != 2)
        return 0;
    strcpy(name->first, first);
    strcpy(name->last, last);
    return 1;
}

int scanDate(Date *date)
{
    int day, year;
    char month[4];
    if (scanf("%d %s %d", &day, month, &year) != 3)
        return 0;
    date->day = day;
    strcpy(date->month, month);
    date->year = year;
    return 1;
}

int scanNID(NID *nid)
{
    printf("Enter full name: ");
    if (!scanName(&nid->full_name))
        return 0;
    printf("Enter father name: ");
    if (!scanName(&nid->father_name))
        return 0;
    printf("Enter mother name: ");
    if (!scanName(&nid->mother_name))
        return 0;
    printf("Enter birth date: ");
    if (!scanDate(&nid->birth_date))
        return 0;
    printf("Enter ID: ");
    if (scanf("%lld", &nid->ID) != 1)
        return 0;
    return 1;
}

int main()
{
    printf("Hello World!\n");
    
    Date birthday;
    birthday.day = 8;
    strcpy(birthday.month, "May");
    birthday.year = 2004;
    printDate(birthday);

    return 0;
}