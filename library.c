#include "library.h"
#include <stdio.h>

int FindOddOccuring(int arr[], int n)
{
    int left=0,right=n,mid=right/2;
    while (right>=left)
    {
        if (arr[mid]==arr[mid+1])
        {
            if ((n-mid)%2==0)
            {
              right=mid-1;
            } else{
                left=mid;
            }
        }
        if (arr[mid]==arr[mid-1])
        {
            if ((n-mid-1)%2==0)
            {
                right=mid;
            } else{
                left=mid+1;
            }
        }
        if(left==right||(arr[mid]!=arr[mid+1]&&arr[mid]!=arr[mid-1]))
        {
            return arr[mid];
        }
    }
}


int main ()
{
    int arr[11]={1,1,3,3,-2,-2,2,5,5,6,6};
    int n=11;

    printf("%d",FindOddOccuring(arr,n));
    return 0;
}

