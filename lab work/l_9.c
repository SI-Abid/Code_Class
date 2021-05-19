/*
    Computerized Phone Directory
    Author: Saiham Islam Abid   (53rd)
*/

// Necessary Header files

#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"

#define DEBUG 0
#define NAMELEN 100
#define NUMLEN 15
#define MAX 400
//  Defining structure 

typedef struct  
{
    int id;
    char name[NAMELEN];
    char number[NUMLEN];
} phone_directory;

//  Global varriables

phone_directory phone[MAX];
char *filename = "phone.txt";
int i;


//  Function prototypes

void save_disk();
void load_disk();
void quit();
void get_number();
void add_number();

//  driver function

int main()
{
    // freopen("in.txt", "w", stdout);
    while(1)
    {
        int co;

        puts("\nWelcome to Computerized Telephone Directory");
        puts("-------------------------------------------");
        puts("1. Enter names and numbers");
        puts("2. Find numbers");
        puts("3. Save directory to disk");
        puts("4. Load directory from disk");
        puts("5. Quit");
        
        printf("Enter you choice: ");
        scanf("%d", &co);
        switch (co)
        {
        case 1:
            add_number();
            break;
        case 2:
            get_number();
            break;
        case 3:
            save_disk();
            puts("\nSaved to disk successfully...\n");
            break;
        case 4:
            load_disk();
            puts("\nLoaded from disk successfully...\n");
            break;
        case 5:
            quit();
            break;
        default:
            break;
        }
        puts("Press any key to continue...");
        getchar();
        getchar();
        }
    return 0;
}

//  User defined functions

void quit()
{
    puts("Thank you for using our service.");
    exit(1);
}

void load_disk()
{
    FILE *fp = fopen(filename, "r");
    
    if(fp != NULL)
    {
        if(DEBUG)   puts("File opened successfully.");
        
        while(fscanf(fp, "%d\n", &i)!=EOF)
        {   
          
            fscanf(fp, "%[^\n]%s", phone[i].name, phone[i].number);
  
            if(DEBUG)   puts(phone[i].name);
            if(DEBUG)   puts(phone[i].number);
            
            i++;
        }

        if(DEBUG)   puts("File loaded successfully");
    
    }
    fclose(fp);
}

void save_disk()
{
    load_disk();

    FILE *fp = fopen(filename, "w");
    
    for(i=0; i<MAX; i++)
    {
        if(strlen(phone[i].name))
        {
            fprintf(fp, "%d\n%s\n%s\n", i, phone[i].name, phone[i].number);
            fputs("\n", fp);
        }
    }
    
    fclose(fp);
}

void add_number()
{
    printf("Enter ID: ");
    scanf("%d", &i);
    printf("Enter name: ");
    getchar();
    scanf("%[^\n]", phone[i].name);
    // getchar();
    printf("Enter number: ");
    getchar();
    scanf("%s", phone[i].number);
    // getchar();
}

void get_number()
{
    load_disk();
    printf("Enter ID: ");
    scanf("%d", &i);
    
    if(strlen(phone[i].name))
        printf("Name: %s\nNumber: %s\n\n", phone[i].name, phone[i].number);
    
    else
    {
        puts("No record");
    }
    
}