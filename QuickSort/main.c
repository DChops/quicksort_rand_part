//
//  main.c
//  QuickSort
//
//  Created by Dhruv Chopra on 21/08/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int SIZE = 30;

void quicksort(int[], int, int);
int partition(int[], int, int);
void swap(int [], int, int);
void mixer(int[], int, int);

int main(int argc, const char * argv[]) {
    
    int Num=0,i=0, Arr[SIZE];
    printf("Please input the array: (Press -1 to stop execution) \n");
    do
    {
        printf("Enter the number: ");
        scanf("%d",&Arr[i]);
        Num++;
        i++;
    }while( Num<SIZE && Arr[i-1]!=-1);
    if( Num!=SIZE ) Num--;
    
    quicksort(Arr, 0, Num-1);
    
    for(i=0; i<Num; i++)
    {
        printf("%d ", Arr[i]);
    }
    return 0;
}

void quicksort(int Arr[SIZE], int m, int n)
{
    if( m>=n )
        return;
    
    int q = partition(Arr,m,n);
    
    quicksort(Arr,m,q-1);
    quicksort(Arr,q+1,n);
}

int partition(int Arr[SIZE], int m, int n)
{
    mixer(Arr, m, n);
    int p = Arr[n];
    int i = m-1;
    int j;
    
    for(j=m; j<n; j++)
    {
        if( Arr[j]<p )
        {
            swap(Arr,j,i+1);
            i++;
        }
    }
    
    swap(Arr, n, i+1);
    return i+1;
}

void mixer(int Arr[SIZE], int a, int b)
{
    srand(time(NULL)%10000);
    int pos = rand()%(b-a);
    swap(Arr, a+pos, b);
}

void swap(int Arr[SIZE], int a, int b)
{
    int temp = Arr[a];
    Arr[a] = Arr[b];
    Arr[b] = temp;
}
