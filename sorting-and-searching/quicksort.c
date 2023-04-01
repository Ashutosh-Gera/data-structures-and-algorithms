#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
    return;
}

int partition(int arr[], int si, int ei)
{
    int x = (si + ((si+ei)/2) + ei)/3; //choosing the index for an even more optimised quicksort
    int cse = 0; // count smaller elem
    
    for (int i = si; i <= ei; i++)
    {
        if (arr[i] < arr[x]) cse++;
    }
    
    swap(arr,x,si+cse);
    
    int i = si; int j = ei; int c = si+cse;
    
    while (i != c && j != c)
    {
        if (arr[i] < arr[c]) i++;
        else if (arr[j] >= arr[c]) j--;
        else
        {
            swap(arr,i,j);
            i++;
            j--;
        }
    }
    return c;
}

void quicksort(int arr[], int si, int ei)
{
    if (si >= ei) return;
    
    int c = partition(arr,si,ei);
    
    quicksort(arr,si,c-1);
    quicksort(arr,c+1,ei);
    return;
}

int main()
{
    int arr[] = {2,3,4,5,1,-8,5};
    quicksort(arr,0,6);

    for (int i = 0; i < 7; i++)
    {
        printf("%i ", arr[i]);
    }
}