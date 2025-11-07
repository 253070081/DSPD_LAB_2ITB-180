#include <stdio.h>
#define SIZE 7
int main() {
int hashTable[SIZE];
int i, key, n, index;
for (i = 0; i < SIZE; i++)
hashTable[i] = -1;
printf("enter number of keys to insert: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("enter key %d: ", i + 1);
scanf("%d", &key);
index = key % SIZE;
while (hashTable[index] != -1)
index = (index + 1) % SIZE;
hashTable[index] = key;
printf("key %d placed at index %d\n", key, index);
}
printf("\nfinal hash table:\n");
for (i = 0; i < SIZE; i++)
printf("Slot %d -> %d\n", i, hashTable[i]);
return 0;
}
