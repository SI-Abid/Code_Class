/****************************************************
*	Assignment-7									*
*	============									*
*													*
*	Prepared By:									*
*	1. Saiham Islam Abid							*
*	2. 												*
*	3.												*
*	4.												*
*													*
*	Date of Submission: 							*
*****************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50000 /// constant
#define INF 2147483647	//2^31 -1  ->   1111111111111111111111111111111

/**************** Global Variables ******************/
int t[SIZE];
int temp;
clock_t start, end;
double totalTime;

/**************** Function Prototypes ***************/
void bubbleSort(int []);
void bubbleSortImproved(int []);
void selectionSort(int []);
void generateArray(int []);

/***************** main() function ******************/
int main()
{
	int a[SIZE];
	srand( time(0) );

	int i;
	for(i=0; i<SIZE; i++)
		a[i] = (rand() % 10000) - 1000;

	// generateArray(a);
	bubbleSort(a);

	// generateArray(a);
	bubbleSortImproved(a);

	// generateArray(a);
	selectionSort(a);

	return 0;
}

/************** User-defined functions **************/

void generateArray(int a[])
{
	int i;
	for(i=0; i<SIZE; i++)
		a[i] = (rand() % 10000) - 1000;
}

void bubbleSort(int a[])
{
	int i, j;

    for(i=0; i<SIZE; i++)
	{
		t[i]=a[i];
	}

	printf("Bubble sort in progress. Please wait ...");
	start = clock();

    //begin

	for(i=0; i<SIZE-1; i++)
    {
        for(j=0; j<SIZE-i-1; j++)
        {
            if(t[j]>t[j+1])
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }

	end = clock();
	totalTime = (end - start) / (CLOCKS_PER_SEC * 1.0);
	printf("\nTime required for Bubble Sort: %.2lf seconds.\n\n", totalTime);
}

void bubbleSortImproved(int a[])
{
	int i, j, swap;

	for(i=0; i<SIZE; i++)
	{
		t[i]=a[i];
	}

	printf("Bubble sort (improved) in progress. Please wait ...");
	start = clock();

	//begin
    for(i=0; i<SIZE-1; i++)
    {
		swap=0;
        for(j=0; j<SIZE-i-1; j++)
        {
            if(t[j]>t[j+1])
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
				swap=1;
            }
        }
		if(swap==0)
		{
			break;
		}
    }
	//end    
	end = clock();
    totalTime = (end - start) / (CLOCKS_PER_SEC * 1.0);
	printf("\nTime required for Improved Bubble Sort: %.4lf seconds.\n\n", totalTime);
}

void selectionSort(int a[])
{
	int i, j, pos;

	for(i=0; i<SIZE; i++)
	{
		t[i]=a[i];
	}

	printf("Selection sort in progress. Please wait ...");
	start = clock();

	//begin

	int min;
	for(i=0; i<SIZE; i++)
	{
		min=INF;
		for(j=i; j<SIZE; j++)
		{
			if(t[j]<min)
			{
				min=t[j];
				pos=j;
			}
		}
		temp = t[i];
		t[i] = t[pos];
		t[pos] = temp;
	}

	//end

	end = clock();
	totalTime = (end - start) / (CLOCKS_PER_SEC * 1.0);
	printf("\nTime required for Selection Sort: %.4lf seconds.\n\n", totalTime);
}