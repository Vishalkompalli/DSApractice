#include <stdio.h>
#include <limits.h>

int maxSubarraysum(int arr[], int n, int k)
{
    // int current_sum = 0;
    // int max_sum=0;
    if(n < k)
    {
        printf("Invalid");
        return INT_MIN;
    }
    int max_sum = INT_MIN;
    int current_sum = 0;

    for(int i=0;i<k;i++)
    {
        current_sum+=arr[i];
    }
    max_sum = current_sum;

    for(int i=k;i<n;i++)
    {
        current_sum-=arr[i-k];
        current_sum+=arr[k];
        if(current_sum > max_sum)
        {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int main()
{
    int arr[] = {1,4,2,10,2,3,1,0,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int max_sum = maxSubarraysum(arr,n,k);
    if(max_sum!=INT_MIN)
    {
        printf("Maximum sum of subarray of size %d is %d\n",k,max_sum);
    }
    return 0;
}