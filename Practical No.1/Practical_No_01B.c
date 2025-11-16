#include <stdio.h>
void printNewArray(int arr[], int start, int end) {
printf("New Array: ");
for (int i = start; i <= end; i++)
printf("%d ", arr[i]);
printf("\n");
}
int* binarySearch(int arr[], int size, int target) {
int start = 0, end = size - 1;
while (start <= end) {
int mid = (start + end) / 2;
printf("checking value %d at index %d\n", arr[mid], mid);
if (arr[mid] == target) {
printf("element found at index %d\n", mid);
return &arr[mid];
}
else if (target > arr[mid]) {
printf("target is greater, moving right\n");
start = mid + 1;
printNewArray(arr, start, end);
}
else {
printf("target is smaller, moving left\n");
end = mid - 1;
printNewArray(arr, start, end);
}
}
printf("element not found\n");
return NULL;
}
int main() {
int size, target;
printf("enter number of elements: ");
scanf("%d", &size);
int arr[size];
printf("enter %d sorted elements: ", size);
for (int i = 0; i < size; i++)
scanf("%d", &arr[i]);
printf("enter element to search: ");
scanf("%d", &target);
int *res = binarySearch(arr, size, target);
if (res != NULL)
printf("%d found in list\n", *res);
else
printf("Element not found\n");
return 0;
}