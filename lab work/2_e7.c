/*
Write a program that will calculate the area of a triangle 
given the coordinates of all three vertices. 
The following formula can be used to calculate the area:
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int ax, ay, bx, by, cx, cy;
    double area;
    
    printf("\t\tArea Calculator\n");
    printf("\t\t===============\n\n");
    printf("Please Enter the coordinates of a triangle:\n");
    
    // take all the inputs
    printf("\tax: ");
    scanf("%d", &ax);
    printf("\tay: ");
    scanf("%d", &ay);
    printf("\tbx: ");
    scanf("%d", &bx);
    printf("\tby: ");
    scanf("%d", &by);
    printf("\tcx: ");
    scanf("%d", &cx);
    printf("\tcy: ");
    scanf("%d", &cy);
    
    //calculate the total area
    area = fabs( (ax*(by-cy) + bx*(cy-ay) + cx*(ay-by)) / 2.0);
    //print the area
    printf("The area is: %lf square units\n", area);

    return 0;
}
