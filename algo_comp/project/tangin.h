#include <stdio.h>

int getDifficulty()
{
    int choice, difficulty;
    printf("Choose your level\n1.Easy\n2.Medium\n3.Hard\nEnter choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            difficulty = 9;
        break;
        
        case 2:
            difficulty = 13;
        break;
        
        case 3:
            difficulty = 18;
        break;
        
    }
    return difficulty;
}