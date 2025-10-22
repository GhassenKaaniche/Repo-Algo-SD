#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    for (int i=0 ; i<n ; i++){
        if (*(arr+i) == target)
        {
            return i;
            break;
        }
    }

    return -1;
}

int jump_search(int *arr, int n, int target)
{ 

    int jump_size = (int)sqrt(n);
    int jump = jump_size;
    int prev = 0;
    while (arr[min_int(jump,n)-1] < target){
        prev = jump;
        jump = jump + jump_size;
        if (prev >= n) return -1;
    }
    for (int i = prev; i < min_int(n,jump); i++){
        if (*(arr+i) == target) 
        {
            return i;
            break;
        }

  }

    return -1;
}

int binary_search(int *arr, int n, int target)
{
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid = (high+low)/2;
        if (arr[mid] == target) {return mid;}
        else if(arr[mid]<target) {
            low = mid + 1;
            }
        else {
            high = mid - 1;
            }
    }

    return -1;
}