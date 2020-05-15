#include<stdio.h>
#include<math.h>

int comparison=0;

int Function_1(int x,int n)
{
comparison++;
if(n==1)
return x;

else if(n==0)
return 1;

else
return (x*Function_1(x,n-1));
}

int Function_2(int x, int n)
{
comparison++;
if(n==1)
return x;

else if(n==0)
return 1;

else
{
 if(n%2==0)
 {
  return (pow(Function_2(x,n/2),2));
 }
 else
 {
  return (x*pow(Function_2(x,n/2),2));
 }
} 
}




int main()
{
printf("\nEnter The Value of base i.e. x: ");
int x;
scanf("%d",&x);

printf("\nEnter The Value Of Exponent i.e. n: ");
int n;
scanf("%d",&n);

int input=0;
int result =0;
while(input!=3)
{
 printf("\nEnter 1 For O(n)\nEnter 2 For O(logn)\nEnter 3 For Exit\n");
 scanf("%d",&input);
;  switch(input)
 {
  case 1: result = Function_1(x,n);
   printf("\nThe Result Is: %d\n",result);
   printf("Total Comparisons= %d\n",comparison);
   comparison=0;
   break;

  case 2: result = Function_2(x,n);
   printf("\nThe Result Is: %d\n",result);
   printf("Total Comparisons= %d\n",comparison);
   comparison=0;
   break;

  case 3:
   break;

  default:
   printf("\nEnter Correct Input\n");
 }  
} 
return 0;
}