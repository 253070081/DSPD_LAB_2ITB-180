#include <stdio.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;
void insert() {
char elem;
if (rear == MAX - 1) {
printf("queue Overflow\n");
} else {
if (front == -1) front = 0;
printf("enter character to insert: ");
scanf(" %c", &elem);
rear++;
queue[rear] = elem;
}
}
void delete() {
if (front == -1 || front > rear) {
printf("queue Underflow\n");
} else {
printf("deleted element: %c\n", queue[front]);
front++;
}
}
void display() {
if (front == -1 || front > rear) {
printf("queue is Empty\n");
} else {
printf("queue Status: ");
int i;
for (i = front; i <= rear; i++) {
printf("%c ", queue[i]);
}
printf("\n");
}
}
int main() {
int choice;
while (1) {
printf("\nmenu:\n");
printf("1. insert Element\n");
printf("2. delete Element\n");
printf("3. display Queue\n");
printf("4. exit\n");
printf("enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("invalid choice.\n");
}
}
return 0;
}