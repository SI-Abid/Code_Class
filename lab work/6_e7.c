#include <stdio.h>

int is_prime(int);
int list_prime(int, int, int []);
int count_pair(int, int []); 

int main()
{
    puts("\t\tPRIME GENERATOR");
    puts("\t\t===============\n");    

    int x, y;
    printf("Enter lower limit: ");
    scanf("%d", &x);
    printf("Enter upper limit: ");
    scanf("%d", &y);

    int size = y-x, pair;
    int arr[size];

    printf("\nThe prime numbers between %d and %d are:\n", x, y);
    
    int prime_count=list_prime(x, y, arr);
    printf("There are %d prime number between %d and %d.\n", prime_count, x, y);
    
    pair = count_pair(size-2, arr);
    printf("There are %d prime pairs\n", pair);
    return 0;
}

int is_prime(int n) //188
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int list_prime(int x, int y, int arr[]) //199
{
    int z=0;
    for(int i=x; i<=y; i++)
    {
        if(is_prime(i))
        {
            printf("%d\t", i);
            arr[z]=i;
            z++;
            if(z%10==0)
                puts("");
        }
    }
    puts("\n");
    return z;
}

int count_pair(int last_index, int arr[]) // 220
{
    int cnt=0;
    for(int i=0; i<=last_index; i++)
    {
        if(arr[i+1]-arr[i]==2) 
            cnt++;
    }
    return cnt;
}

/*
 * 188
 * 199
 * 220
 * 224
func list
    is_prime()          to see if a number is prime or not
    listPrime()         list all primes between x and y [including x, y]
    countPair()         find or count all the prime pairs
    main()              main driver function

person 1: make is_prime function
person 2: make the listPrime function [prime generation in range x->y]
person 3: make the primePair() function [prime pair finding]
person 4: make the main() function and call other functions in it i/o and call func
*/