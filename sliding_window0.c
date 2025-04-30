#include <stdio.h>
#include <limits.h> // For INT_MIN

// Function to find the maximum sum of a subarray of size k
int maxSubarraysum(int arr[], int n, int k)
{
    if(n < k)
    {
        printf("Invalid");
        return INT_MIN;// Indicate an error
    }

    // Initialize the maximum sum and the current window sum
    int max_sum = INT_MIN;
    int current_sum = 0;

    // Calculate the sum of the first window of size k
    for(int i=0;i<k;i++)
    {
        current_sum+=arr[i];
    }

    // Initialize max_sum with the sum of the first window
    max_sum = current_sum;

    // Slide the window one element at a time
    for(int i=k;i<n;i++)
    {
        current_sum-=arr[i-k]; // Subtract the first element of the previous window
        current_sum+=arr[k]; // Add the last element of the current window

        // Update max_sum if the current window sum is greater
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