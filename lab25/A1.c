#include <stdio.h>
// You are given an array of positive integers and an integer K. Find the length of 
// the longest subarray such that the sum of the subarray is less than or equal to K. 
// Input: 
// • An array arr[] of size N 
// • An integer K 
// Output: 
// • Length of the longest subarray with sum ≤ K
// Function to find longest subarray with sum <= K
int longestSubarray(int arr[], int n, int K) {
    int start = 0, sum = 0, maxLen = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];  // include current element

        // shrink window if sum > K
        while (sum > K && start <= end) {
            sum -= arr[start];
            start++;
        }

        // update maximum length
        if (sum <= K) {
            int length = end - start + 1;
            if (length > maxLen) {
                maxLen = length;
            }
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {2, 1, 3, 4, 1, 1, 2, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 7;

    printf("Array: ");
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\nK = %d\n", K);

    int result = longestSubarray(arr, N, K);
    printf("Length of longest subarray with sum <= K: %d\n", result);

    return 0;
}
