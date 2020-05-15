#include<stdio.h>

void towers1(int,char,char,char);
void towers2(int,char,char,char);
int counter1=0;
int counter2=0;

int main()
{
printf("\nEnter The Number Of Disks: ");
int number;
scanf("%d",&number);

printf("The Sequence Of Moves Involved In The Tower Of Hanoi are \n");
printf("\n\nThis is From Version 1\n\n");
towers1(number,'A','C','B');
printf("\nNumber Of Comparisons In Version 1: %d\n",counter1);

printf("\n\nThis Is From Version 2\n\n");
towers2(number,'A','C','B');
printf("\nNumber Of Comparisons In Version 2: %d\n",counter2);

return 0;
}

void towers1(int number,char frompeg, char topeg, char auxpeg)
{
if (number>0)
{
 towers1(number-1,frompeg,auxpeg,topeg);
 counter1++;
 printf("\nMove Disk %d From Peg %c to Peg %c\n",number,frompeg,topeg);
 towers1(number-1,auxpeg,topeg,frompeg);
}
}

void towers2(int number, char frompeg, char topeg, char auxpeg)
{
if (number>0)
{
 towers2(number-1,frompeg,auxpeg,topeg);
 counter2++;
 printf("\nMove Disk %d From Peg %c to Peg %c\n",number,frompeg,topeg);
 towers2(number-1,auxpeg,topeg,frompeg);
 
}
if(number == 1)
{
 number--;
 char temp=frompeg;
 frompeg=auxpeg;
 auxpeg=temp; 
}
} 