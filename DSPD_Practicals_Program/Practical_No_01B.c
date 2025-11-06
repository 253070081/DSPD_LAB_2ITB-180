#include <stdio.h>
int* binarySearch(int arr[], int size, int target) {
if (arr == NULL || size == 0)
return NULL;
int start = 0, end = size - 1;
while (start <= end) {
int mid = (start + end) / 2;
printf("\nchecking value %d at index %d", arr[mid], mid);
if (arr[mid] == target) {
printf("\nelement found at index %d\n", mid);
return &arr[mid];
}
else if (target > arr[mid]) {
printf("\ntarget is greater, moving right");
start = mid + 1;
}
else {
printf("\ntarget is smaller, moving left");
end = mid - 1;
}
}
printf("\nelement not found\n");
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
printf("\n%d found in list\n", *res);
else
printf("\nElement not found\n");
return 0;
}
