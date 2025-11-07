#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
int main() {
struct node *head = NULL, *temp, *newNode;
int num, count = 0;
while (1) {
printf("enter an integer : ");
scanf("%d", &num);
if (num == 0) break;
newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = num;
newNode->next = NULL;
if (head == NULL) head = newNode;
else temp->next = newNode;
temp = newNode;
count++;
}
temp = head;
printf("linked List: ");
while (temp != NULL) {
printf("%d => ", temp->data);
temp = temp->next;
}
printf("NULL\n");
printf("number of nodes: %d\n", count);
return 0;
}
