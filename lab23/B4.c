#include <stdio.h>

// 90. Given an array nums with n objects colored red, white, or blue, sort them in
// place so that objects of the same color are adjacent, with the colors in the order 
// red, white, and blue. We will use the integers 0, 1, and 2 to represent the color 
// red, white, and blue, respectively. 
// Sample Example-1: 
// Input: nums = [2,0,2,1,1,0]    
// Output: [0,0,1,1,2,2] 
// Sample Example-2: 
// Input: nums = [2,0,1]    
// Output: [0,1,2] 
// Function to sort colors in-place
void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else { // nums[mid] == 2
            // Swap nums[mid] and nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums1[] = {2, 0, 2, 1, 1, 0};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Input:  ");
    printArray(nums1, n1);

    sortColors(nums1, n1);

    printf("Output: ");
    printArray(nums1, n1);

    int nums2[] = {2, 0, 1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("\nInput:  ");
    printArray(nums2, n2);

    sortColors(nums2, n2);

    printf("Output: ");
    printArray(nums2, n2);

    return 0;
}
