#include <stdio.h>
struct Student {
int id;
char name[50];
float avg;
};
int main() {
int n;
printf("enter number of students: ");
scanf("%d", &n);
struct Student s[n], temp;
for (int i = 0; i < n; i++) {
printf("\nenter ID, name and avg marks of student %d: ", i + 1);
scanf("%d %s %f", &s[i].id, s[i].name, &s[i].avg);
}
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (s[j].avg < s[j + 1].avg) {
temp = s[j];
s[j] = s[j + 1];
s[j + 1] = temp;
}
}
}
printf("\nstudents sorted by average marks:\n");
for (int i = 0; i < n; i++) {
printf("%d %s %.2f\n", s[i].id, s[i].name, s[i].avg);
}
return 0;
}
