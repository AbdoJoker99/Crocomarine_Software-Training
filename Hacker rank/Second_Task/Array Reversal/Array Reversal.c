// Program to reverse an array

 #include <stdio.h>

 int main() {
 int n;
 scanf("%d", &n);

 int arr[n];
 for(int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }

 // Reverse the array
 for(int i = 0; i < n / 2; i++) {
 int temp = arr[i];
 arr[i] = arr[n - 1 - i];
 arr[n - 1 - i] = temp;
 }

 // Print the reversed array
 for(int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }

 return 0;
 }