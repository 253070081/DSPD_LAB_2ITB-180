#include <stdio.h>
#include <string.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int x) {
if (top == MAX - 1)
printf("stack Overflow\n");
else
stack[++top] = x;
}
void pop() {
if (top == -1)
printf("stack Underflow\n");
else
printf("popped element: %d\n", stack[top--]);
}
void display() {
int i;
if (top == -1)
printf("stack is Empty\n");
else {
printf("stack elements: ");
for (i = top; i >= 0; i--)
printf("%d ", stack[i]);
printf("\n");
}
}
void checkPalindrome() {
char str[50];
int i, len, flag = 1;
printf("Enter a string: ");
scanf("%s", str);
len = strlen(str);
top = -1;
for (i = 0; i < len; i++) push(str[i]);
for (i = 0; i < len; i++) {
if (stack[top--] != str[i]) {
printf("not palindrome\n");
break;
}
}
printf("palindrome\n");

top = -1;
}
int main() {
int choice, val;
while (1) {
printf("\n1. push\n2. pop\n3. check palindrome\n4. display\n5. exit\nenter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("enter element to push: ");
scanf("%d", &val);
push(val);
break;
case 2:
pop();
break;
case 3:
checkPalindrome();
break;
case 4:
display();
break;
case 5:
return 0;
default:
printf("invalid choice\n");
}
}
}