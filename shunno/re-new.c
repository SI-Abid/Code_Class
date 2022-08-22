#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

typedef struct
{
    int p;
    int q;
} Rational;

Rational add(Rational a, Rational b)
{
    Rational c;
    c.p = a.p * b.q + b.p * a.q;
    c.q = a.q * b.q;
    int common = gcd(c.p, c.q);
    c.p /= common;
    c.q /= common;
    return c;
}

Rational subtract(Rational a, Rational b)
{
    return add(a, (Rational){-b.p, b.q});   
}

Rational multiply(Rational a, Rational b)
{
    Rational c;
    c.p = a.p * b.p;
    c.q = a.q * b.q;
    int common = gcd(c.p, c.q);
    c.p /= common;
    c.q /= common;
    return c;
}

Rational divide(Rational a, Rational b)
{
    return multiply(a, (Rational){b.q, b.p});
}

// void print(Rational a)
// {
//     printf("%d/%d\n", a.p, a.q);
// }

// int scan(Rational *a)
// {
//     int p, q;
//     if (scanf("%d/%d", &p, &q) != 2)
//         return 0;
//     a->p = p;
//     a->q = q;
//     return 1;
// }

char toUpper(char c)
{
    return c | 32;
}

char toLower(char c)
{
    return c & ~32;
}

int isPowerOfTwo(int n)
{
    return n && !(n & (n - 1));
}


typedef struct
{
    int id;
    Name name;
} Student;



// int scan(Name *name)
// {
//     char *first, *last;
//     if (scanf("%s %s", &first, &last) != 2)
//         return 0;
//     name->first = first;
//     name->last = last;
//     return 1;
// }
// int scan(Date *date)
// {
//     int day, year;
//     char month[4];
//     if (scanf("%d %s %d", &day, month, &year) != 3)
//         return 0;
//     date->day = day;
//     date->month = month;
//     date->year = year;
//     return 1;
// }
// int scan(NID *nid)
// {
//     printf("Enter full name: ");
//     if (!scan(&nid->full_name))
//         return 0;
//     printf("Enter father name: ");
//     if (!scan(&nid->father_name))
//         return 0;
//     printf("Enter mother name: ");
//     if (!scan(&nid->mother_name))
//         return 0;
//     printf("Enter birth date: ");
//     if (!scan(&nid->birth_date))
//         return 0;
//     printf("Enter ID: ");
//     if (scanf("%lld", &nid->ID) != 1)
//         return 0;
//     return 1;
// }
// void print(Name a)
// {
//     printf("%s %s", a.first, a.last);
// }
// void print(Date a)
// {
//     printf("%0d/%s/%d", a.day, a.month, a.year);
// }
// void print(NID a)
// {
//     printf("Name: ");
//     print(a.full_name);
//     printf("\nFather Name: ");
//     print(a.father_name);
//     printf("\nMother Name: ");
//     print(a.mother_name);
//     printf("\nDate of Birth: ");
//     print(a.birth_date);
//     printf("\nID NO: %lld", a.ID);

// }
int main()
{
    NID my_id;
    // my_id.full_name.first = (char *)malloc(sizeof(char) * 10);
    // my_id.full_name.last = (char *)malloc(sizeof(char) * 10);
    // my_id.father_name.first = (char *)malloc(sizeof(char) * 10);
    // my_id.father_name.last = (char *)malloc(sizeof(char) * 10);
    // my_id.mother_name.first = (char *)malloc(sizeof(char) * 10);
    // my_id.mother_name.last = (char *)malloc(sizeof(char) * 10);
    // my_id.birth_date.month = (char *)malloc(sizeof(char) * 4);

    printf("Enter full name: ");
    scanf("%s %s", my_id.full_name.first, my_id.full_name.last);
    printf("Enter father name: ");
    scanf("%s %s", my_id.father_name.first, my_id.father_name.last);
    printf("Enter mother name: ");
    scanf("%s %s", my_id.mother_name.first, my_id.mother_name.last);
    printf("Enter birth date: ");
    scanf("%d %s %d", &my_id.birth_date.day, my_id.birth_date.month, &my_id.birth_date.year);
    printf("Enter ID: ");
    scanf("%lld", &my_id.ID);

    printf("\nName: %s %s", my_id.full_name.first, my_id.full_name.last);
    printf("\nFather Name: %s %s", my_id.father_name.first, my_id.father_name.last);
    printf("\nMother Name: %s %s", my_id.mother_name.first, my_id.mother_name.last);
    printf("\nDate of Birth: %0d/%s/%d", my_id.birth_date.day, my_id.birth_date.month, my_id.birth_date.year);
    printf("\nID NO: %lld", my_id.ID);
    puts("");

    // Student **students;
    // int no_of_classes;
    // int *students_per_class;
    // FILE *file = fopen("students.txt", "r");
    // if (file == NULL) {
    //     printf("Error opening file\n");
    //     exit(EXIT_FAILURE);
    // }
    // fscanf(file, "%d", &no_of_classes);
    // students = malloc(no_of_classes * sizeof(Student *));
    // students_per_class = malloc(no_of_classes * sizeof(int));
    // for (int i = 0; i < no_of_classes; i++) 
    // {
    //     int no_of_students;
    //     fscanf(file, "%d", &no_of_students);
    //     students[i] = malloc(no_of_students * sizeof(Student));
    //     students_per_class[i] = no_of_students;
    //     for (int j = 0; j < no_of_students; j++) 
    //     {
    //         // printf("%ld\n", ftell(file));
    //         fscanf(file, "%d", &students[i][j].id);
    //         students[i][j].name.first = malloc(20 * sizeof(char));
    //         students[i][j].name.last = malloc(20 * sizeof(char));
    //         fscanf(file, "%s", students[i][j].name.first);
    //         fscanf(file, "%s", students[i][j].name.last);
    //     }
    // }
    // // printf("%ld\n", ftell(file));
    // fclose(file);
    // // print as a table
    // for (int i = 0; i < no_of_classes; i++) 
    // {
    //     printf("Students of class %d\n", i+1);
    //     for (int j = 0; j < students_per_class[i]; j++) 
    //     {
    //         printf("%d %s %s\n", students[i][j].id, students[i][j].name.first, students[i][j].name.last);
    //     }
    // }
    return 0;
}