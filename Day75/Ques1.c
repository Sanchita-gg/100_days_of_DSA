/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5
*/


#include <stdio.h>
#include <stdlib.h>

int maxLen(int arr[], int n) {
    int sum = 0, maxLength = 0;

    int *hash = (int*)malloc(sizeof(int) * 20001);
    for(int i = 0; i < 20001; i++) hash[i] = -2;

    hash[10000] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(hash[sum + 10000] != -2) {
            int len = i - hash[sum + 10000];
            if(len > maxLength) maxLength = len;
        } else {
            hash[sum + 10000] = i;
        }
    }

    free(hash);
    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}