#include <stdio.h>
int main(){
int n,i;
int arr[100];
int sum_even=0,sum_odd=0;
printf("enter the number of elements: ");
scanf("%d",&n);
printf("enter %d numbers:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
if((i+1)%2==0)
sum_even+=arr[i];
else
sum_odd+=arr[i];
}
printf("\nsum of odd position numbers = %d",sum_odd);
printf("\nsum of even position numbers = %d",sum_even);
return 0;
}
